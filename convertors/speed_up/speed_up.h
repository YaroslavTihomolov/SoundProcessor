//
// Created by я on 03.12.2022.
//

#ifndef SOUNDPROCESSOR_SPEED_UP_H
#define SOUNDPROCESSOR_SPEED_UP_H

#include "../converter.h"

class speedup: public convertor {
public:
    speedup();

    unsigned long *convert();
};

std::string description_speed_up = "Speed up convertor:\n"
                               "    value_1 - int value, which mean speed\n"
                               "Convertor mute song sector from value_1 to value_2\n"
                               "example: speedup 2\n\n";

namespace {
    ConverterFactoryRegistration::ConverterFactoryRegistration<speedup> speedup("speedup");
}

namespace add_to_help_2 {
    ParserRegistration::ParserRegistration speedup(description_speed_up);
}

#endif //SOUNDPROCESSOR_SPEED_UP_H
