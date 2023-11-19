cmake_minimum_required(VERSION 3.24)
project(CPPJsonParser)

set(CMAKE_CXX_STANDARD 17)

add_executable(CPPJsonParser main.cpp Lexer.h Lexer.cpp)
