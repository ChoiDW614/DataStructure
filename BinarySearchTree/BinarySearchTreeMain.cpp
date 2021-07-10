#include <iostream>
#include "BinarySearchTree.h"

int main()
{
    BTreeNode * bstRoot;
    BTreeNode * sNode;          // search node

    BSTMakeAndInit(&bstRoot);

    BSTInsert(&bstRoot, 5);
    BSTInsert(&bstRoot, 8);
    BSTInsert(&bstRoot, 1);
    BSTInsert(&bstRoot, 6);
    BSTInsert(&bstRoot, 4);
    BSTInsert(&bstRoot, 9);
    BSTInsert(&bstRoot, 3);
    BSTInsert(&bstRoot, 2);
    BSTInsert(&bstRoot, 7);

    BSTShowAll(bstRoot); std::cout << std::endl;
    sNode = BSTRemove(&bstRoot, 3);
    delete sNode;

    BSTShowAll(bstRoot); std::cout << std::endl;
    sNode = BSTRemove(&bstRoot, 8);
    delete sNode;

    BSTShowAll(bstRoot); std::cout << std::endl;
    sNode = BSTRemove(&bstRoot, 1);
    delete sNode;

    BSTShowAll(bstRoot); std::cout << std::endl;
    sNode = BSTRemove(&bstRoot, 6);
    delete sNode;

    BSTShowAll(bstRoot);
    return 0;
}