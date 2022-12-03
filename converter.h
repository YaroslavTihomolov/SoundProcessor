//
// Created by я on 24.11.2022.
//

#ifndef SOUNDPROCESSOR_CONVERTER_H
#define SOUNDPROCESSOR_CONVERTER_H
#include "WAV.h"
#include "txt_parser.h"
#include "FabricRegistration.h"


class convertor {
public:
    const long samples_in_sec = 44100;
    unsigned long* sec_buffer_1;
    unsigned long* sec_buffer_2;
    convertor() = default;
    virtual unsigned long* convert() {};

    void AddFile_1(unsigned long* inp_sec) {
        sec_buffer_1 = inp_sec;
    }

    void AddFile_2(unsigned long* inp_sec_for_mix) {
        sec_buffer_2 = inp_sec_for_mix;
    }
};

class mute: public convertor {
public:
    mute() = default;
    unsigned long* convert() {
        for (long i = 0; i < samples_in_sec; i++)
            sec_buffer_1[i] = 0;
        return this->sec_buffer_1;
    }
};

namespace {
    ConverterFactoryRegistration::ConverterFactoryRegistration<mute> mute("mute");
}

class mix: public convertor {
public:
    mix() = default;
    unsigned long* convert() {
        for (long i = 0; i < samples_in_sec; i++)
            sec_buffer_1[i] = (sec_buffer_1[i] + sec_buffer_2[i]) / 2;
        return sec_buffer_1;
    }
};

namespace {
    ConverterFactoryRegistration::ConverterFactoryRegistration<mix> mix("mix");
}

#endif //SOUNDPROCESSOR_CONVERTER_H
