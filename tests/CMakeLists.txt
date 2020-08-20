cmake_minimum_required(VERSION 3.16)
project(${tests} CXX)

add_executable(${tests} ${lib_hpp} ${test_hpp} TestMain.cpp)
set_target_properties(${tests} PROPERTIES ${properties})