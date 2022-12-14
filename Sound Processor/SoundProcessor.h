//
// Created by я on 28.11.2022.
//

#ifndef SOUNDPROCESSOR_SOUNDPROCESSOR_H
#define SOUNDPROCESSOR_SOUNDPROCESSOR_H
#include "../Work with wav/WAV.h"
#include "../txt_parser/txt_parser.h"
#include "../convertors/converter.h"

class SoundProcessor {
private:
    wav_file file;
    std::queue<configuration> queue;
    convertor *cur_convert;
    void mute();
    void mix();
    void speedup();
public:
    SoundProcessor(wav_file);
};

#endif //SOUNDPROCESSOR_SOUNDPROCESSOR_H
