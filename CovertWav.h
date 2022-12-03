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
    convert_wav(std::queue<configuration> convert_queue, wav_file *inp, std::vector< std::string > files_inp):
                        queue(convert_queue), input_1(*inp), files(files_inp) {};
    void MakeConvert() {
        convertor *cur_convert;
        int size = queue.size();
        for (int i = 0; i < size; i++) {
            cur_convert = TheConverterFactory::Instance().CreateConverter(queue.front().command);
            if (queue.front().command == "mute") {
                for (int j = queue.front().parameter_1; j < queue.front().parameter_2; j++) {
                    input_1.GoToSecond(j);
                    cur_convert->AddFile_1(input_1.GetSec());
                    input_1.GoToSecond(j);
                    input_1.ChangeLastSec(cur_convert->convert());
                }
            }

            if (queue.front().command == "mix") {
                wav_file file_for_mix(files[queue.front().parameter_1 - 1]);
                int len = std::min(file_for_mix.second_length, input_1.second_length);
                file_for_mix.GoToSecond(queue.front().parameter_2);
                for (int j = queue.front().parameter_2; j < len; j++) {
                    input_1.GoToSecond(j);
                    cur_convert->AddFile_1(input_1.GetSec());
                    cur_convert->AddFile_2(file_for_mix.GetSec());
                    input_1.GoToSecond(j);
                    input_1.ChangeLastSec(cur_convert->convert());
                }
            }

            queue.pop();
        }
    }
};

#endif //SOUNDPROCESSOR_COVERTWAV_H
