cmake_minimum_required(VERSION 3.13)
project(UsefulAlgorithms_Sorting)

set(CMAKE_CXX_STANDARD 17)

add_library(Sorting INTERFACE)
target_include_directories(Sorting INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})