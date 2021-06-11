cmake_minimum_required(VERSION 3.19)
project(RadixSort)

set(CMAKE_CXX_STANDARD 17)

add_executable(RadixSort ListBaseQueue.cpp ListBaseQueue.h RadixSort.cpp)