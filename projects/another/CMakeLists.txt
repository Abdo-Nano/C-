cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 23)

project(another
    VERSION 1.0
    DESCRIPTION "another"
    LANGUAGES CXX
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

# Main application
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

add_executable(another ${SOURCES})
target_include_directories(another PRIVATE include)

############
find_package(SQLiteCpp REQUIRED)
target_link_libraries(another 
  SQLiteCpp
  sqlite3
  pthread
  dl
)

############

# Testing setup
enable_testing()

# Find GTest package
find_package(GTest REQUIRED)

# Create test executable (only include this if you have test files)
file(GLOB TEST_SOURCES "test/*.cpp")
if(TEST_SOURCES)
    add_executable(anotherTests ${TEST_SOURCES})
    target_include_directories(anotherTests PRIVATE include)
    target_link_libraries(anotherTests PRIVATE 
        GTest::GTest 
        GTest::Main
        another  # Link your main library if needed
    )
    add_test(NAME LibraryTests COMMAND anotherTests)
endif()
