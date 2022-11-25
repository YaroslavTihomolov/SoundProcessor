cmake_minimum_required(VERSION 3.20)
project(SoundProcessor)

set(CMAKE_CXX_STANDARD 14)

add_executable(SoundProcessor main.cpp Parser/Parser.h Parser/Parser.cpp WAV.h converter.h Fabriс.h)

set(Boost_INCLUDE_DIR C:/MinGW/include/)
set(Boost_LIBRARY_DIR C:/MinGW/lib/)
find_package(Boost COMPONENTS program_options REQUIRED)
target_include_directories(SoundProcessor PUBLIC ${Boost_INCLUDE_DIR})
target_link_libraries(SoundProcessor ${Boost_LIBRARIES})