cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(CompileTimeVariableList)

add_executable(CompileTimeVariableList fnv.h main.cpp simplex.h testClasses.h testClasses.cpp)