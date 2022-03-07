//#include "BinaryTree.h"
//
//BTreeNode* MakeBTreeNode()
//{
//	BTreeNode* newNode = new BTreeNode;
//	newNode->left = nullptr;
//	newNode->right = nullptr;
//	return newNode;
//}
//
//BTData GetData(BTreeNode* bt)
//{
//	return bt->data;
//}
//
//void SetData(BTreeNode* bt, BTData data)
//{
//	bt->data = data;
//}
//
//BTreeNode* GetLeftSubTree(BTreeNode* bt)
//{
//	return bt->left;
//}
//
//BTreeNode* GetRightSubTree(BTreeNode* bt)
//{
//	return bt->right;
//}
//
//void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
//{
//	if (main->left != nullptr)
//		delete main->left;
//	
//	main->left = sub;
//}
//
//void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
//{
//	if (main->right != nullptr)
//		delete main->right;
//
//	main->right = sub;
//}