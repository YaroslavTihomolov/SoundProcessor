//
// Created by я on 03.12.2022.
//

#ifndef SOUNDPROCESSOR_SLOWED_REVERB_H
#define SOUNDPROCESSOR_SLOWED_REVERB_H

#include "../converter.h"

class speedup: public convertor {
public:
    speedup();

    unsigned long *convert();
};

namespace {
    ConverterFactoryRegistration::ConverterFactoryRegistration<speedup> speedup("speedup");
}

#endif //SOUNDPROCESSOR_SLOWED_REVERB_H
