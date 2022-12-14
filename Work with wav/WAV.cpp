//
// Created by я on 03.12.2022.
//
#include "WAV.h"

wav_file::wav_file() = default;

wav_file::wav_file(std::string file_name, const char* flag_inp):flag(flag_inp) {
    name = file_name;
    sec_buffer = new unsigned long[samples_in_sec];

    open_file(file_name);

    if (f == NULL)
        throw std::invalid_argument("Wav file don't exist");

    fread(&header, sizeof(wav_header_t), 1, f);
    fseek(f, header.fLen - 16, SEEK_CUR);

    while (true) {
        fread(&chunk, sizeof(chunk), 1, f);
        if (*(unsigned long *) &chunk.id == 0x61746164) break;
        fseek(f, chunk.size, SEEK_CUR);
    }

    sample_start_pos = ftell(f);

    samples_count = chunk.size * 8 / header.wBitsPerSample;
    second_length = samples_count / samples_in_sec;

    if (!valid_check()) {
        throw std::invalid_argument("Not supported file encoding");
    }
}

unsigned long* wav_file::GetSec(int second) {
    fseek(f, second * samples_in_sec * short_size + sample_start_pos, SEEK_SET);
    memset(sec_buffer, 0, samples_in_sec);
    for (int i = 0; i < samples_in_sec; i++) {
        fread(&sec_buffer[i], short_size, 1, f);
    }
    return sec_buffer;
}

void wav_file::RecordSpeedHead(int speed, FILE *f_fast) {
    chunk.size /= speed;
    fwrite(&header, sizeof(header), 1, f_fast);
    fwrite(&chunk, sizeof(chunk), 1, f_fast);
}


void wav_file::RecordResult(std::string copy_file) {
    FILE *f_result;
    f_result = fopen(copy_file.c_str(), "wb");

    if (f_result == NULL)
        throw std::invalid_argument(copy_file + " file don't exist");

    fwrite(&header, sizeof(header), 1, f_result);
    fwrite(&chunk, sizeof(chunk), 1, f_result);
    int steps = samples_count / samples_in_sec;
    for (int i = 0; i < steps; i++) {
        GetSec(i);
        for (int j = 0; j < samples_in_sec; j++) {
            fwrite(&sec_buffer[j], short_size, 1, f_result);
        }
    }
    fclose(f_result);
}

bool wav_file::valid_check()  { return  header.nChannels == 1 &&
                                        header.nSamplesPerSec == 44100 &&
                                        header.wBitsPerSample == 16;
}

void wav_file::open_file(std::string file_name) {
    f = fopen(file_name.c_str(), flag);
}

unsigned long* wav_file::operator[](int sec) {
    return GetSec(sec);
}

void wav_file::ChooseFile(std::string name_f, const char* fl) {
    fclose(f);
    flag = fl;
    name = name_f;
    open_file(name_f);
    if (f == NULL)
        throw std::invalid_argument("Wav file don't exist");

    fread(&header, sizeof(wav_header_t), 1, f);
    fseek(f, header.fLen - 16, SEEK_CUR);

    while (true) {
        fread(&chunk, sizeof(chunk), 1, f);
        if (*(unsigned long *) &chunk.id == 0x61746164) break;
        fseek(f, chunk.size, SEEK_CUR);
    }

    sample_start_pos = ftell(f);

    samples_count = chunk.size * 8 / header.wBitsPerSample;
    second_length = samples_count / samples_in_sec;

    if (!valid_check()) {
        throw std::invalid_argument("Not supported file encoding");
    }
}

void wav_file::RemoveFile() {
    fclose(f);
    if (name != Parser::Instance().files[0])
        remove(name.c_str());
}

void wav_file::Rename() {
    remove(Parser::Instance().output.c_str());
    fclose(f);
    rename(name.c_str(), Parser::Instance().output.c_str());
}

wav_file::~wav_file() {
    fclose(f);
}
