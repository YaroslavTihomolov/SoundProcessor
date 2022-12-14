//
// Created by я on 25.11.2022.
//

#ifndef SOUNDPROCESSOR_TXT_PARSER_H
#define SOUNDPROCESSOR_TXT_PARSER_H
#include <string>
#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>
#include "../Exceptions/Exceptions.h"

struct configuration {
    std::string command;
    int parameter_1;
    int parameter_2;
};

class config_file {
private:
    std::string name_of_conf_file;
    std::queue<configuration> queue;
public:
    config_file(const char* name_of_file);

    std::queue<configuration> Read();
};

#endif //SOUNDPROCESSOR_TXT_PARSER_H
