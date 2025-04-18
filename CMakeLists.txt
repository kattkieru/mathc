cmake_minimum_required(VERSION 3.16)
project(mathc LANGUAGES C)

set(CMAKE_C_STANDARD 99)

add_library(mathc STATIC
	mathc.c
	mathc.h
)

target_include_directories(mathc PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
)
