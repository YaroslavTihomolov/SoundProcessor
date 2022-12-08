//
// Created by я on 03.12.2022.
//
#include "txt_parser.h"

config_file::config_file(const char* name_of_file): name_of_conf_file(name_of_file) {}

std::queue<configuration> config_file::Read() {
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

        if (strcmp(config.command.c_str(), "mix") == 0) {
            char res = sscanf(line.c_str(), "%s $%d %d", config.command.c_str(), &config.parameter_1, &config.parameter_2);
                if (res == 2)
                    config.parameter_2 = 0;
                if (res < 2)
                    throw std::invalid_argument("Wrong data in configuration file");
        }

        else if (strcmp(config.command.c_str(), "mute") == 0) {
            if (sscanf(line.c_str(), "%s %d %d", config.command.c_str(), &config.parameter_1, &config.parameter_2) != 3)
                throw std::invalid_argument("Wrong data in configuration file");
        }

        else if (strcmp(config.command.c_str(), "speedup") == 0) {
            if (sscanf(line.c_str(), "%s %d", config.command.c_str(), &config.parameter_1) != 2)
                throw std::invalid_argument("Wrong data in configuration file");
        }

        else throw std::invalid_argument("Wrong converter in configuration file");

        if (config.parameter_2 < 0 || config.parameter_1 < 0)
            throw std::invalid_argument("Wrong parameters in configuration file");
        config_2.command = config.command.c_str();
        config_2.parameter_1 = config.parameter_1;
        config_2.parameter_2 = config.parameter_2;
        queue.push(config_2);
    }
    return queue;
}
