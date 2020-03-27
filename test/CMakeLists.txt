cmake_minimum_required(VERSION 3.13)
project(Algorithms_Tests)

include(CTest)

set(CMAKE_CXX_STANDARD 17)

# Download googletest at configure time
file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/googletest-download)
configure_file(CMakeLists.txt.in ${CMAKE_CURRENT_SOURCE_DIR}/googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/googletest-download)
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()

# Unpack googletest
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

add_subdirectory(googletest-src googletest-build EXCLUDE_FROM_ALL)

enable_testing()

# Create executables, link them against gtest
add_executable(Test_BubbleSort)
target_link_libraries(Test_BubbleSort PRIVATE Sorting gtest)

add_executable(Test_HeapSort)
target_link_libraries(Test_HeapSort PRIVATE Sorting gtest)

add_executable(Test_InsertionSort)
target_link_libraries(Test_InsertionSort PRIVATE Sorting gtest)

add_executable(Test_MergeSort)
target_link_libraries(Test_MergeSort PRIVATE Sorting gtest)

# Set the sources for each target above
add_subdirectory(Sorting)

# Create tests for cmake to run
add_test(BubbleSort Test_BubbleSort)
add_test(HeapSort Test_HeapSort)
add_test(InsertionSort Test_InsertionSort)
add_test(MergeSort Test_MergeSort)
