//
// Created by я on 04.12.2022.
//
#include "converter.h"

convertor::convertor() = default;
unsigned long* convertor::convert() { return 0; }

void convertor::AddFile_1(unsigned long* inp_sec) {
    sec_buffer_1 = inp_sec;
}

void convertor::AddFile_2(unsigned long* inp_sec_for_mix) {
    sec_buffer_2 = inp_sec_for_mix;
}

void convertor::ChooseVolume(int inp_volume) {
    volume = inp_volume;
}
