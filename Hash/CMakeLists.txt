cmake_minimum_required(VERSION 3.19)
project(Hash)

set(CMAKE_CXX_STANDARD 17)

add_executable(Hash Person.h Person.cpp Slot.h Table.h Table.cpp SimpleHashMain.cpp)