#include <iostream>
#include "BinaryTree2.h"
#include "AVLRebalance.h"

BTreeNode* RotateLL(BTreeNode* bst)
{
	BTreeNode* pNode = bst;
	BTreeNode* cNode = GetLeftSubTree(bst);

	ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
	ChangeRightSubTree(cNode, pNode);

	return cNode;
}

BTreeNode* RotateRR(BTreeNode* bst)
{
	BTreeNode* pNode = bst;
	BTreeNode* cNode = GetRightSubTree(bst);

	ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
	ChangeLeftSubTree(cNode, pNode);

	return cNode;
}

BTreeNode* RotateRL(BTreeNode* bst)
{
	BTreeNode* pNode = bst;
	BTreeNode* cNode = GetRightSubTree(bst);

	ChangeRightSubTree(pNode, RotateLL(cNode));
	
	return RotateRR(pNode);
}

BTreeNode* RotateLR(BTreeNode* bst)
{
	BTreeNode* pNode = bst;
	BTreeNode* cNode = GetLeftSubTree(bst);

	ChangeLeftSubTree(pNode, RotateRR(cNode));

	return RotateLL(pNode);
}

int GetHeight(BTreeNode* bst)
{
	int leftH;
	int rightH;

	if (bst == NULL)
		return 0;

	leftH = GetHeight(GetLeftSubTree(bst));
	rightH = GetHeight(GetRightSubTree(bst));

	if (leftH > rightH)
		return leftH + 1;
	else
		return rightH + 1;
}

int GetHeightDiff(BTreeNode* bst)
{
	int lsh;
	int rsh;

	if (bst == NULL)
		return 0;

	lsh = GetHeight(GetLeftSubTree(bst));
	rsh = GetHeight(GetRightSubTree(bst));
	return lsh - rsh;
}

BTreeNode* Rebalance(BTreeNode** pRoot)
{
	int hdiff = GetHeightDiff(*pRoot);

	if (hdiff > 1)
	{
		if (GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)
			*pRoot = RotateLL(*pRoot);
		else
			*pRoot = RotateLR(*pRoot);
	}
	if (hdiff < -1)
	{
		if (GetHeightDiff(GetRightSubTree(*pRoot)) < 0)
			*pRoot = RotateRR(*pRoot);
		else
			*pRoot = RotateRL(*pRoot);
	}
	return *pRoot;
}