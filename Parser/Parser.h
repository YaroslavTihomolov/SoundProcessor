//
// Created by я on 18.11.2022.
//

#ifndef SOUNDPROCESSOR_PARSER_H
#define SOUNDPROCESSOR_PARSER_H

#include <iostream>
#include "boost/program_options.hpp"
#include <string>
#include <vector>


namespace po = boost::program_options;

struct Parser {
    Parser() = default;
    Parser(int, char **);
    static Parser& Instance()
    {
        static Parser theSingleInstance;
        return theSingleInstance;
    }
    void ParserReg(std::string);
    po::variables_map vm;
    std::vector<std::string> files;
    std::string output;
    std::string config;
    std::string help;
};

#endif //SOUNDPROCESSOR_PARSER_H
