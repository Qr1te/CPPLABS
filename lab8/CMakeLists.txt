cmake_minimum_required(VERSION 3.29)
project(lab8)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab8 src/main.cpp
        includes/TreeNode.h
        includes/Tree.h
        includes/Iterator.h
        includes/Algorithm.h
        src/menu.cpp
        includes/menu.h)
