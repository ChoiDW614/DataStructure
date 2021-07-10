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

// Remove a node from the tree and return the value of the address of the removed node
BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target);

// Output data from all nodes stored in the tree
void BSTShowAll(BTreeNode * bst);

#endif //__BINARY_SEARCH_TREE_H__