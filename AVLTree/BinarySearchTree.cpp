#include <iostream>
#include "BinarySearchTree.h"
#include "AVLRebalance.h"

void BSTMakeAndInit(BTreeNode ** pRoot)
{
    *pRoot = nullptr;
}

BSTData BSTGetNodeData(BTreeNode * bst)
{
    return GetData(bst);
}

void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
    BTreeNode * pNode = nullptr;    // parent node
    BTreeNode * cNode = *pRoot;     // current node
    BTreeNode * nNode = nullptr;    // new node

    // Find position that new node will be added
    while(cNode != nullptr)
    {
        if(data == GetData(cNode))
            return;

        pNode = cNode;

        if(data > GetData(cNode))
            cNode = GetRightSubTree(cNode);
        else
            cNode = GetLeftSubTree(cNode);
    }

    // Create a new node to add as a child node of pNode
    nNode = MakeBTreeNode();
    SetData(nNode, data);

    // Add a new node as a child node of pNode
    if(pNode != nullptr)
    {
        if(data > GetData(pNode))
            MakeRightSubTree(pNode, nNode);
        else
            MakeLeftSubTree(pNode, nNode);
    }
    else
    {
        *pRoot = nNode;
    }
    *pRoot = Rebalance(pRoot);
}

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
    BTreeNode * cNode = bst;    // current node
    BSTData cd;                 // current data

    while(cNode != nullptr)
    {
        cd = GetData(cNode);

        if(cd == target)
            return cNode;
        else if(cd > target)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }

    return nullptr;
}

BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target) {
    BTreeNode *pVRoot = MakeBTreeNode();   // virtual root node
    BTreeNode *pNode = nullptr;            // parent node
    BTreeNode *cNode = *pRoot;             // current node
    BTreeNode *dNode;                      // delete node

    ChangeRightSubTree(pVRoot, *pRoot);

    while (cNode != nullptr && GetData(cNode) != target)
    {
        pNode = cNode;
        if (target == GetData(cNode))
            break;
        else if (target > GetData(cNode))
            cNode = GetRightSubTree(cNode);
        else
            cNode = GetLeftSubTree(cNode);
    }

    if(cNode == nullptr)
        return nullptr;

    dNode = cNode;

    if (GetRightSubTree(dNode) == nullptr && GetLeftSubTree(dNode) == nullptr)
    {
        if (GetLeftSubTree(pNode) == dNode)
            RemoveLeftSubTree(pNode);
        else
            RemoveRightSubTree(pNode);
    }
    else if (GetRightSubTree(dNode) == nullptr || GetLeftSubTree(dNode) == nullptr)
    {
        BTreeNode *dcNode;

        if (GetLeftSubTree(dNode) != nullptr)
            dcNode = GetLeftSubTree(dNode);
        else
            dcNode = GetRightSubTree(dNode);

        if (dNode == GetLeftSubTree(pNode))
            ChangeLeftSubTree(pNode, dcNode);
        else
            ChangeRightSubTree(pNode, dcNode);
    }
    else
    {
        BTreeNode *mNode = GetRightSubTree(dNode);     // mNode refers to alternate node
        BTreeNode *mpNode = dNode;                     // mpNode refers to the parent node of an alternate node
        int delData;

        while (GetLeftSubTree(mNode) != nullptr) {
            mpNode = mNode;
            mNode = GetLeftSubTree(mNode);
        }

        delData = GetData(dNode);
        SetData(dNode, GetData(mNode));

        if (GetLeftSubTree(mpNode) == mNode) {
            ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
        } else {
            ChangeRightSubTree(mpNode, GetRightSubTree(mNode));
        }

        dNode = mNode;
        SetData(dNode, delData);
    }

    if(GetRightSubTree(pVRoot) != *pRoot)
        *pRoot = GetRightSubTree(pVRoot);

    delete pVRoot;
    *pRoot = Rebalance(pRoot);
    return dNode;
}

void ShowInData(int data)
{
    std::cout << data << " ";
}

void BSTShowAll(BTreeNode * bst)
{
    InOrderTraverse(bst, ShowInData);
}