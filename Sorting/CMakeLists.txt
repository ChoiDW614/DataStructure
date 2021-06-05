cmake_minimum_required(VERSION 3.19)
project(Sorting)

set(CMAKE_CXX_STANDARD 17)

add_executable(Sorting BubbleSort.cpp SelectionSort.cpp InsertionSort.cpp)