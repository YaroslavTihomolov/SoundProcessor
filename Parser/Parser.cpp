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
    } catch (std::invalid_argument const& ex) {
        throw(ex);
    }

    if (output.find_last_not_of(".wav") == std::string::npos)
        throw("Wrong output file format");

    for (int i = 0; i < files.size(); i++) {
        if (files[i].find_last_not_of(".wav") == std::string::npos)
            throw("Wrong file format");
    }

    if (config.find_last_not_of(".wav") == std::string::npos)
        throw("Wrong config file format");

    if (output.empty())
        throw("Specify output file");

    if (config.empty())
        throw("Specify config file");

    if (vm.count("help")) {
        std::cout << desc << help;
        throw ("call --help\n");
    }
}

void Parser::ParserReg(std::string description) {
    help += description;
}
