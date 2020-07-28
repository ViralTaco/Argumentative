cmake_minimum_required(VERSION 3.16)
project(Argumentative CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Wunreachable-code -Wredundant-decls -Wpadded")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -Og -ggdb3 -fsanitize=undefined")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")

include_directories(.)
include_directories(src)
include_directories(src/argument)
include_directories(src/argumentative)
include_directories(src/utils)

add_executable(Argumentative
        src/argument/*.hpp
        src/argument/Argument.hpp
        src/argument/Flag.hpp
        src/argument/Option.hpp
        src/utils/typealias.hpp
        src/Argumentative.hpp
        src/utils/swap_sign.hpp
        src/argument/errors/InvalidOption.hpp
        Argumentative.cpp)

