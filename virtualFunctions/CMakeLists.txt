cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 23)

project(virtualFunctions
    VERSION 1.0
    DESCRIPTION "virtualFunctions"
    LANGUAGES CXX
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

# Main application
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

add_executable(virtualFunctions ${SOURCES})
target_include_directories(virtualFunctions PRIVATE include)

# Testing setup
enable_testing()

# Find GTest package
find_package(GTest REQUIRED)

# Create test executable (only include this if you have test files)
file(GLOB TEST_SOURCES "test/*.cpp")
if(TEST_SOURCES)
    add_executable(virtualFunctionsTests ${TEST_SOURCES})
    target_include_directories(virtualFunctionsTests PRIVATE include)
    target_link_libraries(virtualFunctionsTests PRIVATE 
        GTest::GTest 
        GTest::Main
        virtualFunctions  # Link your main library if needed
    )
    add_test(NAME LibraryTests COMMAND virtualFunctionsTests)
endif()
