//
// Created by я on 24.11.2022.
//

#ifndef SOUNDPROCESSOR_CONVERTER_H
#define SOUNDPROCESSOR_CONVERTER_H
#include "WAV.h"

class convertor {
public:
    wav_file file_1;
};

class mute: public convertor {
public:
    mute(int start, int end) {
        for (int i = start * file_1.header.nSamplesPerSec; i < end * file_1.header.nSamplesPerSec; i++)
            file_1.value[i] = 0;
    }
};

class mix: public convertor {
public:
    mix(char *file_for_mix, int start, int end) {
        wav_file mix(file_for_mix);
        for (int i = start * file_1.header.nSamplesPerSec; i < end * file_1.header.nSamplesPerSec; i++)
            file_1.value[i] = (file_1.value[i] + mix.value[i]) / 2;
    }
};

#endif //SOUNDPROCESSOR_CONVERTER_H
