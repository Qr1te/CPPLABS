cmake_minimum_required(VERSION 3.29)
project(lab3)

set(CMAKE_CXX_STANDARD 20)

add_executable(inheritance_lab3 src/main.cpp
        src/Article.cpp
        includes/Article.h
        src/LibraryCard.cpp
        includes/LibraryCard.h
        src/Catalog.cpp
        includes/Catalog.h
        src/functions.cpp
        includes/functions.h
)
