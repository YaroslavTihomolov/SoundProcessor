//
// Created by я on 27.11.2022.
//

#ifndef SOUNDPROCESSOR_FABRICREGISTRATION_H
#define SOUNDPROCESSOR_FABRICREGISTRATION_H

#include "Fabric.h"

struct configuration;

namespace ConverterFactoryRegistration {
    template <typename T>
    class ConverterFactoryRegistration
    {
    public:
        ConverterFactoryRegistration() = default;
        ConverterFactoryRegistration(const std::string name) {
            GenericObjectFactory::GenericObjectFactory<std::string, >
        }
    };

}

#endif //SOUNDPROCESSOR_FABRICREGISTRATION_H
