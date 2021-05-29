cmake_minimum_required(VERSION 3.19)
project(Queue)

set(CMAKE_CXX_STANDARD 17)

add_executable(Queue CircularQueueMain.cpp CircularQueue.cpp CircularQueue.h HamburgerSim.cpp)