cmake_minimum_required(VERSION 3.19)
project(Calculator)

set(CMAKE_CXX_STANDARD 17)

add_executable(Calculator ListBaseStack/ListBaseStack.h ListBaseStack/ListBaseStack.cpp
        InfixToPostfix/InfixToPostfix.cpp InfixToPostfix/InfixToPostfix.h InfixToPostfix/InfixToPostfixMain.cpp)