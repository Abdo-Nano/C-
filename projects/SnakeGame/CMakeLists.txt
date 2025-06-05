cmake_minimum_required(VERSION 3.10)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 17)

# Find SFML
find_package(SFML COMPONENTS graphics window system REQUIRED)

# Add executable
add_executable(SnakeGame main.cpp)

# Link SFML libraries
target_link_libraries(SnakeGame sfml-graphics sfml-window sfml-system)
