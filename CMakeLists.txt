cmake_minimum_required(VERSION 3.16)
project(Argumentative CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Wunreachable-code -Wredundant-decls")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -Og -ggdb3 -fsanitize=undefined")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")

include_directories(.)
include_directories(includes)

add_executable(Argumentative
        includes/argumentative/utils/typealias.hpp
        includes/argumentative/utils/swap_sign.hpp
        includes/argumentative/argument/errors/InvalidOption.hpp
        includes/argumentative/argument/Argument.hpp
        includes/argumentative/argument/Option.hpp
        includes/argumentative/argument/Flag.hpp
        includes/argumentative/argument/Help.hpp
        includes/argumentative/argument/Version.hpp
        includes/Argumentative.hpp
        example.cpp)

