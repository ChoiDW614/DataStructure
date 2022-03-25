#include <iostream>
#include "BinaryTree2.h"
#include "BinarySearchTree.h"

int main()
{
	BTreeNode* avlRoot;
	BTreeNode* clNode;
	BTreeNode* crNode;
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

	std::cout << "Root Node: " << GetData(avlRoot) << '\n';
	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);
	std::cout << "left1: " << GetData(clNode) << ", right1: " << GetData(crNode) << '\n';

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	std::cout << "left2: " << GetData(clNode) << ", right2: " << GetData(crNode) << '\n';

	/*
	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	std::cout << "left3: " << GetData(clNode) << ", right3: " << GetData(crNode) << '\n';

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	std::cout << "left4: " << GetData(clNode) << ", right4: " << GetData(crNode) << '\n';
	*/

	return 0;
}