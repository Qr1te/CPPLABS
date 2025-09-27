cmake_minimum_required(VERSION 3.29)
project(lab4)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab4 src/main.cpp
        src/Shape.cpp
        includes/Shape.h
        src/TwoDShape.cpp
        includes/TwoDShape.h
        src/ThreeDShape.cpp
        includes/ThreeDShape.h
        src/Circle.cpp
        includes/Circle.h
        src/Square.cpp
        includes/Square.h
        src/Sphere.cpp
        includes/Sphere.h
        src/Cube.cpp
        includes/Cube.h
        src/functions.cpp
        includes/functions.h)
