//
// Created by я on 28.11.2022.
//

#ifndef SOUNDPROCESSOR_COVERTWAV_H
#define SOUNDPROCESSOR_COVERTWAV_H
#include "WAV.h"
#include "txt_parser.h"
#include "converter.h"

class convert_wav {
private:
    std::queue<configuration> queue;
    wav_file input_1;
    std::vector< std::string > files;
public:
    convert_wav(std::queue<configuration> convert_queue, wav_file inp, std::vector< std::string > files_inp):
                        queue(convert_queue), input_1(inp), files(files_inp) {};
    void MakeConvert() {
        convertor *cur_convert;
        for (int i = 0; i < queue.size(); i++) {
            cur_convert = TheConverterFactory::Instance().CreateConverter(queue.front().command);
            cur_convert->AddWav(input_1);
            cur_convert->AddConf(queue.front());
            cur_convert->AddFile(files);
            cur_convert->convert();
            queue.pop();
        }
    }
};

#endif //SOUNDPROCESSOR_COVERTWAV_H
