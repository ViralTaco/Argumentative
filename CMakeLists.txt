get_filename_component(lib_argumentative
        ${CMAKE_CURRENT_SOURCE_DIR} NAME)
cmake_minimum_required(VERSION 3.12)


project(${lib_argumentative}
        LANGUAGES       CXX
        VERSION         1.6.0
        DESCRIPTION     "Sweetest argument parser ever.")
string(CONCAT tests
        ${lib_argumentative} "Tests")

set(flags "-Wall -Wextra -Wpedantic -Wunreachable-code -Wredundant-decls")
set(properties
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS ON
        CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flags}"
        CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -Og -ggdb3 -fsanitize=undefined"
        CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2 -march=native")

set(lib_hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/argumentative/utils/typealias.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/argumentative/utils/swap_sign.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/argumentative/argument/errors/InvalidOption.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/argumentative/argument/Argument.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/argumentative/argument/Option.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/argumentative/argument/Flag.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/argumentative/argument/Help.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/argumentative/argument/Version.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Argumentative.hpp)
set(test_hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/assert.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/TestArgument.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tests/TestCase.hpp)

add_executable(${lib_argumentative} example.cpp ${lib_hpp})
set_target_properties(${lib_argumentative} PROPERTIES ${properties})
add_subdirectory(tests)
add_custom_target(ALL_TESTS ALL DEPENDS ${lib_argumentative} COMMAND ${tests})