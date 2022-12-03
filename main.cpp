#include "WAV.h"
#include "txt_parser.h"
#include "Parser/Parser.h"
#include "CovertWav.h"

int main(int argc, char **argv) {
    Parser input(argc, argv);
    wav_file input_1(input.files[0]);
    input_1.RecordResult(input.output);
    wav_file result(input.output);
    config_file s(input.config.c_str());
    std::queue<configuration> queue = s.Read();
    convert_wav conv(queue, &result, input.files);
    conv.MakeConvert();
    return 0;
}