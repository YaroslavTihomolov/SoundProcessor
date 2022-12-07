//
// Created by я on 27.11.2022.
//

#ifndef SOUNDPROCESSOR_FABRICREGISTRATION_H
#define SOUNDPROCESSOR_FABRICREGISTRATION_H

#include "Fabric.h"

struct configuration;

namespace ConverterFactoryRegistration {
    template <typename T, class ...Args>
    class ConverterFactoryRegistration
    {
    public:
        ConverterFactoryRegistration() = default;
        ConverterFactoryRegistration(const std::string name) {
            TheConverterFactory::Instance().RegisterConverter(
                    name,
                    [](Args...args) { return static_cast<convertor*>(new T(args...)); }
            );
        }
    };

}

#endif //SOUNDPROCESSOR_FABRICREGISTRATION_H
