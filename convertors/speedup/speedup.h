//
// Created by я on 03.12.2022.
//

#ifndef SOUNDPROCESSOR_SPEEDUP_H
#define SOUNDPROCESSOR_SPEEDUP_H

#include "../converter.h"

class speedup: public convertor {
public:
    speedup();

    unsigned long *convert();
};

namespace {
    ConverterFactoryRegistration::ConverterFactoryRegistration<speedup> speedup("speedup");
}

#endif //SOUNDPROCESSOR_SPEEDUP_H
