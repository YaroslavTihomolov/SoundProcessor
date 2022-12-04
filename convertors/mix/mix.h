//
// Created by я on 03.12.2022.
//

#ifndef SOUNDPROCESSOR_MIX_H
#define SOUNDPROCESSOR_MIX_H

#include "../converter.h"

class mix: public convertor {
public:
    mix();
    unsigned long* convert();
};

std::string description_mix = "Mix convertor:\n"
                              "    value_1 - int value, which mean number of file for mix, written after $\n"
                              "    value_2 - int value, which mean second of start mix\n"
                              "Convertor mix song with song with number value_1 in sector from value_2 to end\n"
                              "example: mix $2 45\n\n";

namespace {
    ConverterFactoryRegistration::ConverterFactoryRegistration<mix> mix("mix");
}

namespace add_to_help_2 {
    ParserRegistration::ParserRegistration mute(description_mix);
}

#endif //SOUNDPROCESSOR_MIX_H
