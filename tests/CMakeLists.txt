cmake_minimum_required(VERSION 3.16)
project(ArgumentativeTest CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Wunreachable-code -Wredundant-decls")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -Og -ggdb3 -fsanitize=undefined")

include_directories(.)
include_directories(../include)

add_executable(ArgumentTest
        ../include/argumentative/utils/typealias.hpp
        ../include/argumentative/utils/swap_sign.hpp
        ../include/argumentative/argument/errors/InvalidOption.hpp
        ../include/argumentative/argument/Argument.hpp
        ../include/argumentative/argument/Option.hpp
        ../include/argumentative/argument/Flag.hpp
        ../include/argumentative/argument/Help.hpp
        ../include/argumentative/argument/Version.hpp
        assert.hpp
        TestArgument.hpp
        TestCase.hpp
        TestMain.cpp)