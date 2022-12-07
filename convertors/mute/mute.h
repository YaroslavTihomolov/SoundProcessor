//
// Created by я on 03.12.2022.
//

#ifndef SOUNDPROCESSOR_MUTE_H
#define SOUNDPROCESSOR_MUTE_H

#include "../converter.h"

class mute: public convertor {
public:
    mute();
    unsigned long* convert();
};

std::string description_mute = "Mute convertor:\n"
                          "    value_1 - int value, which mean second of mute start\n"
                          "    value_2 - int value, which mean second of mute finish\n"
                          "Convertor mute song sector from value_1 to value_2\n"
                          "example: mute 0 30\n";

namespace {
    ConverterFactoryRegistration::ConverterFactoryRegistration<mute> mute("mute");
}

namespace add_to_help_1 {
    ParserRegistration::ParserRegistration mute(description_mute);
}

#endif //SOUNDPROCESSOR_MUTE_H
