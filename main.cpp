#include "WAV.h"
#include "txt_parser.h"
#include "Parser/Parser.h"
#include "CovertWav.h"

int main(int argc, char **argv) {
    wav_file input_1("severe_tire_damage.wav");
    Parser input(argc, argv);
    config_file s(input.config.c_str());
    std::queue<configuration> queue = s.Read();
    convert_wav conv(queue, input_1, input.files);
    conv.MakeConvert();
    input_1.Record();
    return 0;
}