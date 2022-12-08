//
// Created by я on 04.12.2022.
//
#include "converter.h"

converter::converter() = default;
unsigned long* converter::convert() { return 0; }

void converter::AddFile_1(unsigned long* inp_sec) {
    sec_buffer_1 = inp_sec;
}

void converter::AddFile_2(unsigned long* inp_sec_for_mix) {
    sec_buffer_2 = inp_sec_for_mix;
}

void converter::ChooseSpeed(int inp_volume) {
    speed = inp_volume;
}
