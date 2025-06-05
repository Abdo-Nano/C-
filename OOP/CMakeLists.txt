cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 23) 


project(OOP
    VERSION 1.0
    DESCRIPTION "OOP"
    LANGUAGES CXX
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

add_executable(OOP ${SOURCES})


target_include_directories(OOP PRIVATE include)
