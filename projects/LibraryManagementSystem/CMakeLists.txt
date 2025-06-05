


cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 23)

project(LibraryManagementSystem
    VERSION 1.0
    DESCRIPTION "LibraryManagementSystem"
    LANGUAGES CXX
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

# Main application sources
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

# Main application executable
add_executable(LibraryManagementSystem ${SOURCES})
target_include_directories(LibraryManagementSystem PRIVATE include)

# Testing setup
enable_testing()

# Find GTest - try both modern and legacy approaches
find_package(GTest REQUIRED)

# Testing setup (only if test files exist)
file(GLOB TEST_SOURCES "test/*.cpp")
if(TEST_SOURCES)
    enable_testing()
    find_package(GTest REQUIRED)
    add_executable(LibraryTests ${TEST_SOURCES})
    target_link_libraries(LibraryTests PRIVATE GTest::GTest GTest::Main)
    add_test(NAME LibraryTests COMMAND LibraryTests)
endif()
