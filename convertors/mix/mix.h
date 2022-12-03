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

namespace {
    ConverterFactoryRegistration::ConverterFactoryRegistration<mix> mix("mix");
}

#endif //SOUNDPROCESSOR_MIX_H
