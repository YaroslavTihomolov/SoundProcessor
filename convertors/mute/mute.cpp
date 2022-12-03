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
