//
// Created by я on 03.12.2022.
//
#include "speedup.h"

speedup::speedup() {}


unsigned long* speedup::convert() {
    int len = samples_in_sec / speed;
    for (long i = 0; i < len; i++)
        sec_buffer_1[i] = sec_buffer_1[i * 2];
    return this->sec_buffer_1;
}

