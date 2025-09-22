cmake_minimum_required(VERSION 3.29)
project(inheritance_lab3)

set(CMAKE_CXX_STANDARD 20)

add_executable(inheritance_lab3 main.cpp
        Article.cpp
        Article.h
        LibraryCard.cpp
        LibraryCard.h
        Catalog.cpp
        Catalog.h
        functions.cpp
        functions.h
)
