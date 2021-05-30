cmake_minimum_required(VERSION 3.19)
project(ExpressionTree)

set(CMAKE_CXX_STANDARD 17)

add_executable(ExpressionTree ListBaseStack.cpp ListBaseStack.h
        BinaryTree.cpp BinaryTree.h
        ExpressionTree.h ExpressionTree.cpp ExpressionTreeMain.cpp)