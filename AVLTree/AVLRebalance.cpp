#include <iostream>
#include "BinaryTree.h"
#include "AVLRebalance.h"

BTreeNode * RotateLL(BTreeNode * bst)
{
    BTreeNode * pNode;      // parent node
    BTreeNode * cNode;      // child node

    pNode = bst;
    cNode = GetLeftSubTree(pNode);

    // Two functions responsible for LL rotation
    ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
    ChangeRightSubTree(cNode, pNode);

    return cNode;
}

BTreeNode * RotateRR(BTreeNode * bst)
{
    BTreeNode * pNode;      // parent node
    BTreeNode * cNode;      // child node

    pNode = bst;
    cNode = GetRightSubTree(pNode);

    // Two functions responsible for RR rotation
    ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
    ChangeLeftSubTree(cNode, pNode);

    return cNode;
}

BTreeNode * RotateLR(BTreeNode * bst)
{
    BTreeNode * pNode;
    BTreeNode * cNode;

    pNode = bst;
    cNode = GetLeftSubTree(pNode);

    ChangeLeftSubTree(pNode, RotateRR(cNode));
    RotateLL(pNode);

    return cNode;
}

BTreeNode * RotateRL(BTreeNode * bst)
{
    BTreeNode * pNode;
    BTreeNode * cNode;

    pNode = bst;
    cNode = GetRightSubTree(pNode);

    ChangeRightSubTree(pNode, RotateLL(cNode));
    RotateRR(pNode);

    return cNode;
}

int GetHeight(BTreeNode * bst)
{
    int leftH;      // left height
    int rightH;     // right height

    if(bst == nullptr)
        return 0;

    leftH = GetHeight(GetLeftSubTree(bst));
    rightH = GetHeight(GetRightSubTree(bst));

    // return the height of a large value
    if(leftH > rightH)
        return leftH + 1;
    else
        return rightH + 1;
}

int GetHeightDiff(BTreeNode * bst)
{
    int lsh;        // left sub tree height
    int rsh;        // right sub tree height

    if(bst == nullptr)
        return 0;

    lsh = GetHeight(GetLeftSubTree(bst));
    rsh = GetHeight(GetRightSubTree(bst));
    return lsh - rsh;
}

BTreeNode * Rebalance(BTreeNode ** pRoot)
{
    int HDiff = GetHeightDiff(*pRoot);

    if(HDiff > 1)
    {
        if(GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)
            *pRoot = RotateLL(*pRoot);
        else
            *pRoot = RotateLR(*pRoot);
    }
    if(HDiff < -1)
    {
        if(GetHeightDiff(GetRightSubTree(*pRoot)) < 0)
            *pRoot = RotateRR(*pRoot);
        else
            *pRoot = RotateRL(*pRoot);
    }

    return *pRoot;
}