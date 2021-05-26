cmake_minimum_required(VERSION 3.19)
project(Stack)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Stack
        .idea/.gitignore
        .idea/modules.xml
        .idea/Stack.iml
        .idea/vcs.xml
        .idea/workspace.xml
        ArrayBaseStack.cpp
        ArrayBaseStack.h
        ArrayBaseStackMain.cpp
        ListBaseStack.cpp
        ListBaseStack.h
        ListBaseStackMain.cpp
        Stack.vcxproj
        Stack.vcxproj.filters)
