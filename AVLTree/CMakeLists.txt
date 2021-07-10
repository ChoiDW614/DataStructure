cmake_minimum_required(VERSION 3.19)
project(AVLTree)

set(CMAKE_CXX_STANDARD 17)

add_executable(AVLTree BinaryTree.h BinaryTree.cpp BinarySearchTree.h BinarySearchTree.cpp AVLRebalance.cpp AVLRebalance.h AVLTreeMain.cpp)