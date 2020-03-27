cmake_minimum_required(VERSION 3.13)
project(Algorithms_Tests_Sorting)

set(CMAKE_CXX_STANDARD 17)

# Set target sources
target_sources(Test_BubbleSort PRIVATE bubble.cpp)
target_sources(Test_HeapSort PRIVATE heap.cpp)
target_sources(Test_InsertionSort PRIVATE insertion.cpp)
target_sources(Test_MergeSort PRIVATE merge.cpp)