cmake_minimum_required(VERSION 3.20)
project(SoundProcessor)

set(CMAKE_CXX_STANDARD 14)

add_executable(SoundProcessor main.cpp Parser/Parser.h Parser/Parser.cpp "Work with wav/WAV.h"
        convertors/converter.h Fabric/Fabric.h txt_parser/txt_parser.h Fabric/FabricRegistration.h
        Fabric/Fabric.cpp "Sound Processor/SoundProcessor.h" "Work with wav/WAV.cpp"
        convertors/mute/mute.h convertors/mix/mix.h convertors/mute/mute.cpp convertors/mix/mix.cpp
        txt_parser/txt_parser.cpp "Sound Processor/SoundProcessor.cpp" convertors/speed_up/speed_up.h
        convertors/speed_up/speed_up.cpp Parser/ParserRegistration.h convertors/converter.cpp Exception_class/Exception.h test.cpp)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

target_link_libraries(SoundProcessor gtest_main)

set(Boost_INCLUDE_DIR C:/MinGW/include/)
set(Boost_LIBRARY_DIR C:/MinGW/lib/)
find_package(Boost COMPONENTS program_options REQUIRED)
target_include_directories(SoundProcessor PUBLIC ${Boost_INCLUDE_DIR})
target_link_libraries(SoundProcessor ${Boost_LIBRARIES})
