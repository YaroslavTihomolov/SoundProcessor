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
    wav_header_t header;
public:
    int second_length;

    wav_file();

    wav_file(std::string file_name);

    void GoToSecond(int second);

    unsigned long* GetSec();

    void ChangeLastSec(unsigned long* changed_sec_buffer);

    void RecordResult(std::string copy_file);

    ~wav_file();
};

#endif //SOUNDPROCESSOR_WAV_H
