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
    configuration conf;
    wav_file file_1;
    convertor() = default;
    std::vector< std::string > files;
    virtual void convert() {};

    void AddConf(configuration conf_input) {
        conf = conf_input;
    }

    void AddWav(wav_file inp_wav) {
        file_1 = inp_wav;
    }

    void AddFile(std::vector< std::string > files_inp) {
        files = files_inp;
    }
};

class mute: public convertor {
public:
    mute() = default;
    void convert() {
        for (int i = conf.parameter_1 * file_1.header.nSamplesPerSec; i < conf.parameter_2 * file_1.header.nSamplesPerSec; i++)
            file_1.value[i] = 0;
    }
};

namespace {
    ConverterFactoryRegistration::ConverterFactoryRegistration<mute> mute("mute");
}

class mix: public convertor {
public:
    mix() = default;
    void convert() {
        wav_file mix(files[conf.parameter_1 - 2]);
        for (int i = conf.parameter_1 * file_1.header.nSamplesPerSec; i < conf.parameter_2 * file_1.header.nSamplesPerSec; i++)
            file_1.value[i] = (file_1.value[i] + mix.value[i]) / 2;
    }
};

namespace {
    ConverterFactoryRegistration::ConverterFactoryRegistration<mix> mix("mix");
}

#endif //SOUNDPROCESSOR_CONVERTER_H
