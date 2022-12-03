//
// Created by я on 28.11.2022.
//

#ifndef SOUNDPROCESSOR_COVERTWAV_H
#define SOUNDPROCESSOR_COVERTWAV_H
#include "../Work with wav/WAV.h"
#include "../txt_parser/txt_parser.h"
#include "../convertors/converter.h"

class convert_wav {
private:
    std::queue<configuration> queue;
    wav_file input_1;
    std::vector< std::string > files;
public:
    convert_wav(std::queue<configuration> convert_queue, wav_file *inp, std::vector< std::string > files_inp);

    void MakeConvert();
};

#endif //SOUNDPROCESSOR_COVERTWAV_H
