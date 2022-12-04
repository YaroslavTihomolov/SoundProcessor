#include "Work with wav/WAV.h"
#include "txt_parser/txt_parser.h"
#include "Parser/Parser.h"
#include "ConverWav/CovertWav.h"

int main(int argc, char **argv) {
    Parser::Instance().ParsInput(argc, argv);
    wav_file input_1(Parser::Instance().files[0]);
    input_1.RecordResult(Parser::Instance().output);
    wav_file result(Parser::Instance().output);
    config_file s(Parser::Instance().config.c_str());
    std::queue<configuration> queue = s.Read();
    convert_wav conv(queue, &result, Parser::Instance().files);
    conv.MakeConvert();
    return 0;
}