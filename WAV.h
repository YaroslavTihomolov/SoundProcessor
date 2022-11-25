//
// Created by я on 19.11.2022.
//

#ifndef SOUNDPROCESSOR_WAV_H
#define SOUNDPROCESSOR_WAV_H

class wav_file {
private:
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
    unsigned long samples;
    int samples_count;
    chunk_t chunk;
public:
    wav_header_t header;
    unsigned long *value;
    wav_file(char *file_name) {
        FILE *f = fopen(file_name, "rb");
        fread(&header, sizeof(wav_header_t), 1, f);
        fseek(f, header.fLen - 16, SEEK_CUR);

        while (true) {
            fread(&chunk, sizeof(chunk), 1, f);
            if (*(unsigned long *) &chunk.id == 0x61746164) break;
            fseek(f, chunk.size, SEEK_CUR); //skip chunk data bytes
        }
        samples_count = chunk.size * 8 / header.wBitsPerSample;
        value = new unsigned long[samples_count];
        memset(value, 0, sizeof(unsigned long) * samples_count);
        int sample_size = header.wBitsPerSample / 8;

        for (int i = 0; i < samples_count; i++) {
            fread(&value[i], sample_size, 1, f);
        }

        fclose(f);
    }

    void Record() {
        FILE *f1 = fopen("result.wav", "wb");
        fwrite(&header, sizeof(header), 1, f1);
        fwrite(&chunk, sizeof(chunk), 1, f1);

        for (int i = 0; i < samples_count; i++) {
            fwrite(&value[i], sizeof(short), 1, f1);
        }
        fclose(f1);
    }
};

#endif //SOUNDPROCESSOR_WAV_H
