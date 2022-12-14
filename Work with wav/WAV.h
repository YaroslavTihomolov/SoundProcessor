//
// Created by я on 19.11.2022.
//

#ifndef SOUNDPROCESSOR_WAV_H
#define SOUNDPROCESSOR_WAV_H
#include <fstream>
#include <cstring>
#include <iostream>
#include "../Parser/Parser.h"

class wav_file {
private:
    bool valid_check();
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

    std::string name;
    int samples_count;
    chunk_t chunk;
    FILE *f;
    unsigned long *sec_buffer;
    int sample_start_pos;
    char short_size = 2;
    wav_header_t header;
    const char* flag;
    void open_file(std::string);
public:
    int second_length;

    void ChooseFile(std::string, const char*);

    wav_file();

    wav_file(std::string, const char*);

    unsigned long* GetSec(int);


    void RecordResult(std::string);

    void RecordSpeedHead(int, FILE*);

    void RecordSpeedSample(unsigned long*, FILE*, int);

    void RemoveFile();

    unsigned long* operator[](int);

    void Rename();

    ~wav_file();
};

#endif //SOUNDPROCESSOR_WAV_H
