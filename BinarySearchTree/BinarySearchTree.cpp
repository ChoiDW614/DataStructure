#include <iostream>
#include "BinarySearchTree.h"

void BSTMakeAndInit(BTreeNode ** pRoot)
{
    *pRoot = nullptr;
}

BSTData BSTGetNodeData(BTreeNode * bst)
{
    return GetData(bst);
}

void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
    BTreeNode * pNode = nullptr;    // parent node
    BTreeNode * cNode = *pRoot;     // current node
    BTreeNode * nNode = nullptr;    // new node

    // Find position that new node will be added
    while(cNode != nullptr)
    {
        




    }

    // Create a new node to add as a child node of pNode


    // Add a new node as a child node of pNode


}

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{

}

