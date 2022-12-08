//
// Created by я on 03.12.2022.
//
#include "SoundProcessor.h"

void SoundProcessor::speedup() {
    FILE *tmp = fopen("tmp.wav", "rb+");
    file.RecordSpeedHead(queue.front().parameter_1, tmp);
    int speed = queue.front().parameter_1;
    for (int j = 0; j < file.second_length; j++) {
        cur_convert->AddFile_1(file.GetSec(j));
        cur_convert->ChooseSpeed(speed);
        file.RecordSpeedSample(cur_convert->convert(), tmp, speed);
    }
    file.second_length /= file.second_length;
    fclose(tmp);
    wav_file tmp_w("tmp.wav");
    tmp_w.RecordResult(Parser::Instance().output);
}
/*void SoundProcessor::speedup() {
    FILE *tmp = fopen("tmp.wav", "rb+");
    file.RecordSpeedHead(queue.front().parameter_1, tmp);
    int speed = queue.front().parameter_1;
    cur_convert->ChooseSpeed(speed);
    for (int j = 0; j < file.second_length; j++) {
        file.GoToSecond(j);
        file.RecordSpeedSample(cur_convert->convert(file.GetSec()), tmp, speed);
    }
    file.second_length /= file.second_length;
    fclose(tmp);
    wav_file tmp_w("tmp.wav");
    tmp_w.RecordResult(Parser::Instance().output);
}*/

void SoundProcessor::mute() {
    for (int j = queue.front().parameter_1; j < queue.front().parameter_2; j++) {
        cur_convert->AddFile_1(file.GetSec(j));
        file.ChangeLastSec(cur_convert->convert(), j);
    }
}

void SoundProcessor::mix() {
    if (Parser::Instance().files.size() <= queue.front().parameter_1 - 1)
        throw std::invalid_argument("Wrong link for mix file");

    wav_file file_for_mix(Parser::Instance().files[queue.front().parameter_1 - 1]);
    int len = std::min(file_for_mix.second_length, file.second_length);

    for (int j = queue.front().parameter_2; j < len; j++) {
        cur_convert->AddFile_1(file.GetSec(j));
        cur_convert->AddFile_2(file_for_mix.GetSec(j));
        file.ChangeLastSec(cur_convert->convert(), j);
    }
}


SoundProcessor::SoundProcessor(wav_file inp_wav) {
    file = inp_wav;
    config_file s(Parser::Instance().config.c_str());
    queue = s.Read();
    int size = queue.size();
    for (int i = 0; i < size; i++) {
        std::shared_ptr<converter> convert(GenericObjectFactory<std::string, converter>::Instance().get(queue.front().command.data())());
        cur_convert = convert;
        if (queue.front().command == "mute") mute();
        if (queue.front().command == "mix") mix();
        if (queue.front().command == "speedup") speedup();
        queue.pop();
    }
}
