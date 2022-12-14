//
// Created by я on 13.12.2022.
//
#include <gtest/gtest.h>
#include "Work with wav/WAV.h"
#include "txt_parser/txt_parser.h"
#include "Sound Processor/SoundProcessor.h"

TEST(SoundProcessor, output_wrong_format) {
    int argc = 4;
    char *argv[] = {"--config=config.txt", "--output=result.wv",  "--files=Japan.wav", "--files=funkorama.wav"};
    EXPECT_ANY_THROW(Parser::Instance().ParsInput(argc, argv));
}

TEST(SoundProcessor, files_wrong_format) {
    int argc = 4;
    char *argv[] = {"--config=config.txt", "--output=result.wav",  "--files=Japan", "--files=funkorama.wav"};
    ASSERT_ANY_THROW(Parser::Instance().ParsInput(argc, argv));
}

TEST(SoundProcessor, empty_output) {
    int argc = 4;
    char *argv[] = {"--config=config.tx", " ",  "--files=Japan.wav", "--files=funkorama.wav"};
    ASSERT_ANY_THROW(Parser::Instance().ParsInput(argc, argv));
}

TEST(SoundProcessor, empty_config) {
    int argc = 4;
    char *argv[] = {" ", "--output=result",  "--files=Japan.wav", "--files=funkorama.wav"};
    ASSERT_ANY_THROW(Parser::Instance().ParsInput(argc, argv));
}

/*TEST(SoundProcessor, wrong_format) {
    int argc = 4;
    char *argv[] = {"--config=config.txt", "--output=result",  "--files=Japan.wav", "--files=funkorama.wav"};
    ASSERT_ANY_THROW(Parser::Instance().ParsInput(argc, argv));
}*/

/*GTEST_API_ int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}*/

