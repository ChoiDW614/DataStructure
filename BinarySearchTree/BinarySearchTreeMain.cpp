#include <iostream>
#include "BinarySearchTree.h"

int main()
{
    BTreeNode * bstRoot;
    BTreeNode * sNode;          // search node

    BSTMakeAndInit(&bstRoot);

    BSTInsert(&bstRoot, 9);
    BSTInsert(&bstRoot, 1);
    BSTInsert(&bstRoot, 6);
    BSTInsert(&bstRoot, 2);
    BSTInsert(&bstRoot, 8);
    BSTInsert(&bstRoot, 3);
    BSTInsert(&bstRoot, 5);

    sNode = BSTSearch(bstRoot, 1);
    if(sNode == nullptr)
        std::cout << "Search fail" << std::endl;
    else
        std::cout << "Key : " << BSTGetNodeData(sNode) << std::endl;

    sNode = BSTSearch(bstRoot, 4);
    if(sNode == nullptr)
        std::cout << "Search fail" << std::endl;
    else
        std::cout << "Key : " << BSTGetNodeData(sNode) << std::endl;

    sNode = BSTSearch(bstRoot, 6);
    if(sNode == nullptr)
        std::cout << "Search fail" << std::endl;
    else
        std::cout << "Key : " << BSTGetNodeData(sNode) << std::endl;

    sNode = BSTSearch(bstRoot, 7);
    if(sNode == nullptr)
        std::cout << "Search fail" << std::endl;
    else
        std::cout << "Key : " << BSTGetNodeData(sNode) << std::endl;

    return 0;
}