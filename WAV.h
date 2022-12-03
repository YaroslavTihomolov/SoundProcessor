//
// Created by я on 19.11.2022.
//

#ifndef SOUNDPROCESSOR_WAV_H
#define SOUNDPROCESSOR_WAV_H
#include <fstream>
#include <cstring>
#include <iostream>

class wav_file {
private:
    static const int samples_in_sec = 44100;
    struct wav_header_t {
        char rId[4];
        unsigned long rLen;
        char wId[4];
        char fId[4];
        unsigned long fLen;
        unsigned short wFormatTag;
        unsigned short nChannels;
        unsigned long nSamplesPerSec;
        unsigned long nAvgBytesPerSec;
        unsigned short nBlockAlign;
        unsigned short wBitsPerSample;
    };
    struct chunk_t {
        char id[4];
        unsigned long size;
    };
    int samples_count;
    chunk_t chunk;
    FILE *f;
    unsigned long *sec_buffer;
    int sample_start_pos;
    char short_size = 2;
public:
    int second_length;
    wav_file() = default;
    wav_header_t header;
    wav_file(std::string file_name) {
        sec_buffer = new unsigned long[samples_in_sec];

        f = fopen(file_name.c_str(), "rb+");
        fread(&header, sizeof(wav_header_t), 1, f);
        fseek(f, header.fLen - 16, SEEK_CUR);

        sample_start_pos = sizeof(wav_header_t) + header.fLen - 16;

        while (true) {
            fread(&chunk, sizeof(chunk), 1, f);
            sample_start_pos += sizeof(chunk);
            if (*(unsigned long *) &chunk.id == 0x61746164) break;
            fseek(f, chunk.size, SEEK_CUR); //skip chunk data bytes
            sample_start_pos += chunk.size;
        }
        samples_count = chunk.size * 8 / header.wBitsPerSample;
        second_length = samples_count / samples_in_sec;
    }

    void GoToSecond(int second) {
        fseek(f, second * samples_in_sec * short_size + sample_start_pos, SEEK_SET);
    }

    unsigned long* GetSec() {
        memset(sec_buffer, 0, samples_in_sec);
        for (int i = 0; i < samples_in_sec; i++) {
            fread(&sec_buffer[i], short_size, 1, f);
        }
        return sec_buffer;
    }

    void ChangeLastSec(unsigned long* changed_sec_buffer) {
        //fseek(f, -samples_in_sec, SEEK_CUR);
        for (int j = 0; j < samples_in_sec; j++) {
            fwrite(&changed_sec_buffer[j], short_size, 1, f);
        }
    }

    void RecordResult(std::string copy_file) {
        FILE *f_result;
        f_result = fopen(copy_file.c_str(), "wb");
        fwrite(&header, sizeof(header), 1, f_result);
        fwrite(&chunk, sizeof(chunk), 1, f_result);
        int steps = samples_count / samples_in_sec;
        for (int i = 0; i < steps; i++) {
            GetSec();
            for (int j = 0; j < samples_in_sec; j++) {
                fwrite(&sec_buffer[j], short_size, 1, f_result);
            }
        }
        fclose(f_result);
    }

    ~wav_file() {
        fclose(f);
    }
};

#endif //SOUNDPROCESSOR_WAV_H
