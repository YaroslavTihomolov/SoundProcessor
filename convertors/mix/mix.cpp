//
// Created by я on 03.12.2022.
//
#include "mix.h"

mix::mix() = default;

unsigned long* mix::convert() {
    for (long i = 0; i < samples_in_sec; i++)
        sec_buffer_1[i] = (sec_buffer_1[i] + sec_buffer_2[i]) / 2;
    return sec_buffer_1;
}

std::string mix::description() {
    return "Mix convertor:"
           "    value_1 - int value, which mean number of file for mix, written after '$'"
           "    value_2 - int value, which mean second of start mix"
           "Convertor mix song with song with number value_1 in sector from value_2 to end"
           "example: mix $2 45";
}
