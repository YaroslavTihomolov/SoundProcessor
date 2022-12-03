//
// Created by я on 24.11.2022.
//

#ifndef SOUNDPROCESSOR_CONVERTER_H
#define SOUNDPROCESSOR_CONVERTER_H
#include "../Work with wav/WAV.h"
#include "../txt_parser/txt_parser.h"
#include "../Fabric/FabricRegistration.h"


class convertor {
public:
    const long samples_in_sec = 44100;
    unsigned long* sec_buffer_1;
    unsigned long* sec_buffer_2;

    convertor();

    virtual unsigned long* convert();

    void AddFile_1(unsigned long* inp_sec);

    void AddFile_2(unsigned long* inp_sec_for_mix);
};

#endif //SOUNDPROCESSOR_CONVERTER_H
