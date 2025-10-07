cmake_minimum_required(VERSION 3.29)
project(lab2)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab2 src/main.cpp
        src/String.cpp
        includes/String.h
        src/functions.cpp
        includes/functions.h)
