//
// Created by я on 24.11.2022.
//

#ifndef SOUNDPROCESSOR_FABRIC_H
#define SOUNDPROCESSOR_FABRIC_H

#include <unordered_map>
#include <string>

class convertor;

typedef convertor*(*converterInstanceGenerator)();

class TheConverterFactory {
public:
    static TheConverterFactory& Instance()
    {
        static TheConverterFactory theSingleInstance;
        return theSingleInstance;
    }

    void RegisterConverter(const std::string, const converterInstanceGenerator&);
    convertor* CreateConverter(std::string);

private:
    std::unordered_map <std::string, converterInstanceGenerator> converts;
    TheConverterFactory(){}
    TheConverterFactory(const TheConverterFactory& root) = delete;
    TheConverterFactory& operator=(const TheConverterFactory) = delete;
};


#endif //SOUNDPROCESSOR_FABRIC_H
