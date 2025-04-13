cmake_minimum_required(VERSION 3.10)
project(Tetris)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add all source files
file(GLOB SOURCES "src/*.cpp")

# Add executable
add_executable(tetris ${SOURCES})

# Include header files directory
target_include_directories(tetris PRIVATE include)