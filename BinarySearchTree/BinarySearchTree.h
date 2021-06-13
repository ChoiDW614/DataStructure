#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include "BinaryTree.h"

typedef BTData BSTData;

// Create and initialize BST
void BSTMakeAndInit(BTreeNode ** pRoot);

// Return data stored on node
BSTData BSTGetNodeData(BTreeNode * bst);

// Save the data to BST
void BSTInsert(BTreeNode ** pRoot, BSTData data);

// Search the data to BST
BTreeNode * BSTSearch(BTreeNode * bst, BSTData target);

#endif //__BINARY_SEARCH_TREE_H__
