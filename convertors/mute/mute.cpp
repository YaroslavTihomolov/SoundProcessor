//
// Created by я on 03.12.2022.
//
#include "mute.h"

mute::mute() = default;

unsigned long* mute::convert() {
    for (long i = 0; i < samples_in_sec; i++)
        sec_buffer_1[i] = 0;
    return this->sec_buffer_1;
}

std::string mute::description() {
    return "Mute convertor:"
           "    value_1 - int value, which mean second of mute start"
           "    value_2 - int value, which mean second of mute finish"
           "Convertor mute song sector from value_1 to value_2"
           "example: mute 0 30";
}
