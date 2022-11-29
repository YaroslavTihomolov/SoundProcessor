//
// Created by я on 25.11.2022.
//

#ifndef SOUNDPROCESSOR_TXT_PARSER_H
#define SOUNDPROCESSOR_TXT_PARSER_H
#include <string>
#include <iostream>
#include <fstream>
#include <queue>

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
    config_file(const char* name_of_file): name_of_conf_file(name_of_file){};
    std::queue<configuration> Read() {
        std::ifstream file(name_of_conf_file);
        std::string line;
        while (std::getline(file, line)) {
            if (line[0] == '#')
                continue;
            configuration config;
            configuration config_2;
            sscanf(line.c_str(), "%s", config.command.c_str());
            if (!strcmp(config.command.c_str(), "mix") && !strcmp(config.command.c_str(), "mute"))
                throw std::invalid_argument("Wrong data in configuration file");
            if (strcmp(config.command.c_str(), "mix") == 0)
                if (sscanf(line.c_str(), "%s $%d %d", config.command.c_str(), &config.parameter_1, &config.parameter_2) != 3)
                    throw std::invalid_argument("Wrong data in configuration file");
            if (strcmp(config.command.c_str(), "mute") == 0)
                if (sscanf(line.c_str(), "%s %d %d", config.command.c_str(), &config.parameter_1, &config.parameter_2) != 3)
                    throw std::invalid_argument("Wrong data in configuration file");
            config_2.command = config.command.c_str();
            config_2.parameter_1 = config.parameter_1;
            config_2.parameter_2 = config.parameter_2;
            queue.push(config_2);
        }
        return queue;
    }
};

#endif //SOUNDPROCESSOR_TXT_PARSER_H
