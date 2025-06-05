
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 23)

project(Pointers
    VERSION 1.0
    DESCRIPTION "Pointers"
    LANGUAGES CXX
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

# Main application
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

add_executable(Pointers ${SOURCES})
target_include_directories(Pointers PRIVATE include)

# Testing setup
enable_testing()

# Find GTest package
find_package(GTest REQUIRED)

# Create test executable (only include this if you have test files)
file(GLOB TEST_SOURCES "test/*.cpp")
if(TEST_SOURCES)
    add_executable(PointersTests ${TEST_SOURCES})
    target_include_directories(PointersTests PRIVATE include)
    target_link_libraries(PointersTests PRIVATE 
        GTest::GTest 
        GTest::Main
        Pointers  # Link your main library if needed
    )
    add_test(NAME LibraryTests COMMAND PointersTests)
endif()