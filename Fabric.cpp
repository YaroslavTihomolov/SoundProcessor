//
// Created by я on 27.11.2022.
//
#include "Fabric.h"

void TheConverterFactory::RegisterConverter(const std::string name, const converterInstanceGenerator & strategyFn) {
    converts.insert(std::make_pair(name, strategyFn));
}

convertor* TheConverterFactory::CreateConverter(std::string converter_name) {
    auto it = converts.find(converter_name);
    if (it == converts.end()) {
        throw ("Неизвестный идентификатор");
    }
    return (it->second());
}
