#include <iostream>
#include "BinaryTree.h"
#include "BinarySearchTree.h"

int main()
{
    BTreeNode  * avlRoot;
    BTreeNode  * clNode;        // current left node
    BTreeNode  * crNode;        // current right node
    BSTMakeAndInit(&avlRoot);

    BSTInsert(&avlRoot, 1);
    BSTInsert(&avlRoot, 2);
    BSTInsert(&avlRoot, 3);
    BSTInsert(&avlRoot, 4);
    BSTInsert(&avlRoot, 5);
    BSTInsert(&avlRoot, 6);
    BSTInsert(&avlRoot, 7);
    BSTInsert(&avlRoot, 8);
    BSTInsert(&avlRoot, 9);

    std::cout << "Root node: " << GetData(avlRoot) << std::endl;

    clNode = GetLeftSubTree(avlRoot);
    crNode = GetRightSubTree(avlRoot);
    std::cout << "Left 1 : " << GetData(clNode) << "   " << "Right 1 : " << GetData(crNode) << std::endl;

    clNode = GetLeftSubTree(clNode);
    crNode = GetRightSubTree(crNode);
    std::cout << "Left 2 : " << GetData(clNode) << "   " << "Right 2 : " << GetData(crNode) << std::endl;

    clNode = GetLeftSubTree(clNode);
    crNode = GetRightSubTree(crNode);
    std::cout << "Left 3 : " << GetData(clNode) << "   " << "Right 3 : " << GetData(crNode) << std::endl;

    clNode = GetLeftSubTree(clNode);
    crNode = GetRightSubTree(crNode);
    std::cout << "Left 4 : " << GetData(clNode) << "   " << "Right 4 : " << GetData(crNode) << std::endl;
    return 0;
}