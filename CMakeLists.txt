cmake_minimum_required(VERSION 3.24)
project(CPPJsonParser)

set(CMAKE_CXX_STANDARD 17)

add_executable(CPPJsonParser main.cpp Lexer.h Lexer.cpp Parser.cpp Parser.h Value.cpp Value.h Object.cpp Object.h Array.cpp Array.h String.cpp String.h Number.cpp Number.h Keyword.cpp Keyword.h)
