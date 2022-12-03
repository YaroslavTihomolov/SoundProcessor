//
// Created by я on 27.11.2022.
//

#ifndef SOUNDPROCESSOR_FABRICREGISTRATION_H
#define SOUNDPROCESSOR_FABRICREGISTRATION_H

#include "Fabric.h"

class wav_file;
struct configuration;

namespace ConverterFactoryRegistration {
    template <typename T>
    class ConverterFactoryRegistration
    {
    public:
        ConverterFactoryRegistration() = default;
        ConverterFactoryRegistration(const std::string name) {
            TheConverterFactory::Instance().RegisterConverter(
                    name,
                    []() { return static_cast<convertor*>(new T()); }
            );
        }
    };

}

#endif //SOUNDPROCESSOR_FABRICREGISTRATION_H
