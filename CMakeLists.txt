cmake_minimum_required(VERSION 3.20)
project(SoundProcessor)

set(CMAKE_CXX_STANDARD 14)

add_executable(SoundProcessor main.cpp Parser/Parser.h Parser/Parser.cpp "Work with wav/WAV.h" convertors/converter.h Fabric/Fabric.h txt_parser/txt_parser.h Fabric/FabricRegistration.h Fabric/Fabric.cpp "Sound Processor/SoundProcessor.h" "Work with wav/WAV.cpp" convertors/mute/mute.h convertors/mix/mix.h convertors/mute/mute.cpp convertors/mix/mix.cpp txt_parser/txt_parser.cpp "Sound Processor/SoundProcessor.cpp" convertors/speedup/speedup.h convertors/speedup/speedup.cpp Parser/ParserRegistration.h convertors/converter.cpp)

set(Boost_INCLUDE_DIR C:/MinGW/include/)
set(Boost_LIBRARY_DIR C:/MinGW/lib/)
find_package(Boost COMPONENTS program_options REQUIRED)
target_include_directories(SoundProcessor PUBLIC ${Boost_INCLUDE_DIR})
target_link_libraries(SoundProcessor ${Boost_LIBRARIES})
