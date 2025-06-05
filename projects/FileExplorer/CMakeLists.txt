cmake_minimum_required(VERSION 3.31)
project(FileExplorer)

set(CMAKE_CXX_STANDARD 23)

add_executable(FileExplorer main.cpp
        BasicFileOperations.cpp
        BasicFileOperations.h)
