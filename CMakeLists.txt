cmake_minimum_required(VERSION 3.26)
project(BFInterpreter C)

set(CMAKE_C_STANDARD 23)

add_executable(BFInterpreter main.c
        memory_tape.c
        memory_tape.h)
