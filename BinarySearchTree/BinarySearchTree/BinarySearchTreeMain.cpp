//#include <iostream>
//#include "BinarySearchTree.h"
//
//int main()
//{
//	BTreeNode* bstRoot;
//	BTreeNode* sNode;
//
//	BSTMakeAndInit(&bstRoot);
//
//	BSTInsert(&bstRoot, 9);
//	BSTInsert(&bstRoot, 1);
//	BSTInsert(&bstRoot, 6);
//	BSTInsert(&bstRoot, 2);
//	BSTInsert(&bstRoot, 8);
//	BSTInsert(&bstRoot, 3);
//	BSTInsert(&bstRoot, 5);
//
//	sNode = BSTSearch(bstRoot, 1);
//	if (sNode == nullptr)
//		std::cout << "fail to search" << '\n';
//	else
//		std::cout << "key value: " << sNode->data << '\n';
//
//	sNode = BSTSearch(bstRoot, 4);
//	if (sNode == nullptr)
//		std::cout << "fail to search" << '\n';
//	else
//		std::cout << "key value: " << sNode->data << '\n';
//
//	sNode = BSTSearch(bstRoot, 6);
//	if (sNode == nullptr)
//		std::cout << "fail to search" << '\n';
//	else
//		std::cout << "key value: " << sNode->data << '\n';
//
//	sNode = BSTSearch(bstRoot, 7);
//	if (sNode == nullptr)
//		std::cout << "fail to search" << '\n';
//	else
//		std::cout << "key value: " << sNode->data << '\n';
//
//	return 0;
//}