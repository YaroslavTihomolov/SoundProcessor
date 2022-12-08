//
// Created by я on 03.12.2022.
//

#ifndef SOUNDPROCESSOR_SPEEDUP_H
#define SOUNDPROCESSOR_SPEEDUP_H

#include "../converter.h"

class speedup: public converter {
public:
    speedup();
    unsigned long *convert();
};

namespace {
    bool add = GenericObjectFactory<std::string, converter>::Instance().add<speedup>("speedup");
}

#endif //SOUNDPROCESSOR_SPEEDUP_H
