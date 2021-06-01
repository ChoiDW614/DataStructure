cmake_minimum_required(VERSION 3.19)
project(Heap)

set(CMAKE_CXX_STANDARD 17)

add_executable(Heap SimpleHeap/SimpleHeap.h SimpleHeap/SimpleHeap.cpp SimpleHeap/SimpleHeapMain.cpp)