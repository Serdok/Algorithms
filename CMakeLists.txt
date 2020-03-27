cmake_minimum_required(VERSION 3.13)
project(UsefulAlgorithms)

set(CMAKE_CXX_STANDARD 17)

# Main library
add_subdirectory(Sorting)

# Tests
add_subdirectory(test)