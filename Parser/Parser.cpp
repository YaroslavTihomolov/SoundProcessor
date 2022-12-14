//
// Created by я on 18.11.2022.
//
//
// Created by я on 06.11.2022.
//
#include "Parser.h"

void Parser::ParsInput(int argc, char** argv) {
    po::options_description desc("Generate parameters");
    desc.add_options()
            ("help", "produce help message")
            ("output", po::value<std::string>(&output), "--output=[File_Name.wav]")
            ("files", po::value < std::vector < std::string > >(&files), "--files={File_Name.wav}")
            ("config", po::value< std::string >(&config), "--config=[File_Name.txt]");

    try {
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);
    } catch (po::error &e) {
        throw Exceptions(e.what(), BAD_PROG_ARGS);
    }

    if (output.find(".wav") == std::string::npos)
        throw Exceptions("Wrong output file format", WRONG_FORMAT);

    for (int i = 0; i < files.size(); i++) {
        if (files[i].find(".wav") == std::string::npos)
            throw Exceptions("Wrong file format", WRONG_FORMAT);
    }

    if (config.find(".txt") == std::string::npos)
        throw Exceptions("Wrong config file format", WRONG_FORMAT);

    if (output.empty())
        throw Exceptions("Specify output file", WRONG_PROG_ARGS);

    if (config.empty())
        throw Exceptions("Specify config file", WRONG_PROG_ARGS);

    if (vm.count("help")) {
        std::cout << desc << help;
        throw ("call --help\n");
    }
}

void Parser::ParserReg(std::string description) {
    help += description;
}
