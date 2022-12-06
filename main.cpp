#include "Work with wav/WAV.h"
#include "txt_parser/txt_parser.h"
#include "Parser/Parser.h"
#include "Sound Processor/SoundProcessor.h"
#include <windows.h>

int main(int argc, char **argv) {
    try {
        Parser::Instance().ParsInput(argc, argv);
        wav_file input_1(Parser::Instance().files[0]);
        input_1.RecordResult(Parser::Instance().output);
        wav_file result(Parser::Instance().output);
        SoundProcessor conv(result);
    } catch (std::invalid_argument const& ex) {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h, 4);
        std::cout << ex.what() << '\n';
    }

    return 0;
}