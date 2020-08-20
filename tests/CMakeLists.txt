cmake_minimum_required(VERSION 3.12)
project(${tests}
        LANGUAGES   CXX
        VERSION     1.1.0
        DESCRIPTION "Simplest Tests Ever… ish.")

add_executable(${tests} ${lib_hpp} ${test_hpp} TestMain.cpp)
set_target_properties(${tests} PROPERTIES ${properties})