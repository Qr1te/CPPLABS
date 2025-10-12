cmake_minimum_required(VERSION 3.29)
project(lab6)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab6 src/main.cpp
        src/StringException.cpp
        includes/StringException.h
        src/String.cpp
        includes/String.h
        src/OutOfRangeException.cpp
        includes/OutOfRangeException.h
        src/Menu.cpp
        includes/Menu.h
        src/InvalidArgumentException.cpp
        includes/InvalidArgumentException.h
        src/OverflowException.cpp
        includes/OverflowException.h
        src/UnderflowException.cpp
        includes/UnderflowException.h
        src/MemoryAllocationException.cpp
        includes/MemoryAllocationException.h)
