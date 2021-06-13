#include <iostream>
#include "BinarySearchTree.h"

void BSTMakeAndInit(BTreeNode ** pRoot);

// Return data stored on node
BSTData BSTGetNodeData(BTreeNode * bst);

// Save the data to BST
void BSTInsert(BTreeNode ** pRoot, BSTData data);

// Search the data to BST
BTreeNode * BSTSearch(BTreeNode * bst, BSTData target);