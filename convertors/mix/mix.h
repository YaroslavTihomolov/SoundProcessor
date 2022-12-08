//
// Created by я on 03.12.2022.
//

#ifndef SOUNDPROCESSOR_MIX_H
#define SOUNDPROCESSOR_MIX_H

#include "../converter.h"
#include "../../Fabric/Fabric.h"

class mix: public converter {
public:
    mix() = default;

    unsigned long* convert() {
        for (long i = 0; i < samples_in_sec; i++)
            sec_buffer_1[i] = (sec_buffer_1[i] + sec_buffer_2[i]) / 2;
        return sec_buffer_1;
    }
};

std::string description_mix = "Mix converter:\n"
                              "    value_1 - int value, which mean number of file for mix, written after $\n"
                              "    value_2 - int value, which mean second of start mix\n"
                              "Convertor mix song with song with number value_1 in sector from value_2 to end\n"
                              "example: mix $2 45\n\n";

namespace {
    bool add = GenericObjectFactory<std::string, converter>::Instance().add<mix>("mix");
}

namespace add_to_help_2 {
    __attribute__((unused)) ParserRegistration::ParserRegistration mute(description_mix);
}

#endif //SOUNDPROCESSOR_MIX_H
