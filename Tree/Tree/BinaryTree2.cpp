#include "BinaryTree2.h"
#include <iostream>

BTreeNode* MakeBTreeNode()
{
	BTreeNode* newNode = new BTreeNode;
	newNode->left = nullptr;
	newNode->right = nullptr;
	return newNode;
}

BTData GetData(BTreeNode* bt)
{
	return bt->data;
}

void SetData(BTreeNode* bt, BTData data)
{
	bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt)
{
	return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode* bt)
{
	return bt->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->left != nullptr)
		delete main->left;

	main->left = sub;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->right != nullptr)
		delete main->right;

	main->right = sub;
}

void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == nullptr)
		return;

	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}

void InorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == nullptr)
		return;

	InorderTraverse(bt->left, action);
	action(bt->data);
	InorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == nullptr)
		return;

	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);
}

void DeleteTree(BTreeNode* bt)
{	
	if (bt == nullptr)
		return;
	DeleteTree(bt->left);
	DeleteTree(bt->right);

	std::cout << "delete: " << bt->data << "\n";
	delete bt;
}