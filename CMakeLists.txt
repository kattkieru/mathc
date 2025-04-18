cmake_minimum_required(VERSION 3.16)
project(mathc LANGUAGES C)

set(CMAKE_C_STANDARD 99)

add_library(mathc STATIC
    mathc.c
)

target_include_directories(mathc PUBLIC
    .
)

