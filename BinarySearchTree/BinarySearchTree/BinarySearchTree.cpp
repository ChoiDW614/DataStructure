#include "BinarySearchTree.h"
#include "AVLRebalance.h"
#include <iostream>

void BSTMakeAndInit(BTreeNode** pRoot)
{
	*pRoot = nullptr;
}

BSTData BSTGetNodeData(BTreeNode* bst)
{
	return GetData(bst);
}

//void BSTInsert(BTreeNode** pRoot, BSTData data)
//{
//	BTreeNode* pNode = nullptr;		// parent node
//	BTreeNode* cNode = *pRoot;		// current node
//	BTreeNode* nNode = nullptr;		// new node
//
//	while (cNode != nullptr) {
//		if (data == GetData(cNode))
//			return;
//		pNode = cNode;
//
//		if (GetData(cNode) > data)
//			cNode = GetLeftSubTree(cNode);
//		else
//			cNode = GetRightSubTree(cNode);
//	}
//
//	nNode = MakeBTreeNode();
//	SetData(nNode, data);
//
//	if (pNode != nullptr) {
//		if (data < GetData(pNode))
//			MakeLeftSubTree(pNode, nNode);
//		else
//			MakeRightSubTree(pNode, nNode);
//	}
//	else {
//		*pRoot = nNode;
//	}
//	if(pNode == nullptr )
//	*pRoot = Rebalance(pRoot);
//}

BTreeNode* BSTInsert(BTreeNode** pRoot, BSTData data)
{
	if (*pRoot == nullptr)
	{
		*pRoot = MakeBTreeNode();
		SetData(*pRoot, data);
	}
	else if (data < GetData(*pRoot))
	{
		BSTInsert(&((*pRoot)->left), data);
		*pRoot = Rebalance(pRoot);
	}
	else if (data > GetData(*pRoot))
	{
		BSTInsert(&((*pRoot)->right), data);
		*pRoot = Rebalance(pRoot);
	}
	else
	{
		return nullptr;
	}
	return *pRoot;
}

BTreeNode* BSTSearch(BTreeNode* bst, BSTData target)
{
	BTreeNode* cNode = bst;

	while (cNode != nullptr) {
		
		if (target == GetData(cNode))
			return cNode;
		else if (GetData(cNode) > target)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	return nullptr;
}

BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target)
{
	BTreeNode* pVRoot = MakeBTreeNode();
	BTreeNode* pNode = pVRoot;
	BTreeNode* cNode = *pRoot;
	BTreeNode* dNode;
	ChangeRightSubTree(pVRoot, *pRoot);

	while (cNode != nullptr && GetData(cNode) != target) {
		pNode = cNode;
		if (GetData(cNode) > target)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}
	if (cNode == nullptr)
		return nullptr;
	dNode = cNode;

	if (GetLeftSubTree(dNode) == nullptr && GetRightSubTree(dNode) == nullptr) {
		if (GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}
	else if (GetLeftSubTree(dNode) == nullptr || GetRightSubTree(dNode) == nullptr) {
		if (GetLeftSubTree(dNode) != nullptr)
			if(GetLeftSubTree(pNode) == dNode)
				ChangeLeftSubTree(pNode, GetLeftSubTree(dNode));
			else
				ChangeRightSubTree(pNode, GetLeftSubTree(dNode));
		else
			if (GetLeftSubTree(pNode) == dNode)
				ChangeLeftSubTree(pNode, GetRightSubTree(dNode));
			else
				ChangeRightSubTree(pNode, GetRightSubTree(dNode));
	}
	else {
		BTreeNode* mNode = GetRightSubTree(dNode);
		BTreeNode* mpNode = dNode;
		int delData;

		while (GetLeftSubTree(mNode) != nullptr)
		{
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		delData = GetData(dNode);
		SetData(dNode, GetData(mNode));

		if (GetLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else 
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));
		
		dNode = mNode;
		SetData(dNode, delData);
	}

	if (GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot);

	delete pVRoot;
	*pRoot = Rebalance(pRoot);
	return dNode;
}

void ShowIntData(int data)
{
	std::cout << data << " ";
}

void BSTShowAll(BTreeNode* bst)
{
	InorderTraverse(bst, ShowIntData);
}