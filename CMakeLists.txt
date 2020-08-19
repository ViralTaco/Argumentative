cmake_minimum_required(VERSION 3.16)
project(Argumentative CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Wunreachable-code -Wredundant-decls")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -Og -ggdb3 -fsanitize=undefined")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")

include_directories(.)
include_directories(include)

add_executable(Argumentative
        include/argumentative/utils/typealias.hpp
        include/argumentative/utils/swap_sign.hpp
        include/argumentative/argument/errors/InvalidOption.hpp
        include/argumentative/argument/Argument.hpp
        include/argumentative/argument/Option.hpp
        include/argumentative/argument/Flag.hpp
        include/argumentative/argument/Help.hpp
        include/argumentative/argument/Version.hpp
        include/Argumentative.hpp
        example.cpp)

