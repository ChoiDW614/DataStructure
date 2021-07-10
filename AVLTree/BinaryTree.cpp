#include <iostream>
#include "BinaryTree.h"

BTreeNode * MakeBTreeNode()
{
    BTreeNode *newNode;
    newNode = new BTreeNode;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

BTData GetData(BTreeNode * bt)
{
    return bt->data;
}

void SetData(BTreeNode * bt, BTData data)
{
    bt->data = data;
}

BTreeNode * GetLeftSubTree(BTreeNode * bt)
{
    return bt->left;
}

BTreeNode * GetRightSubTree(BTreeNode * bt)
{
    return bt->right;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{
    if(main->left != nullptr)
    {
        delete main->left;
    }

    main->left = sub;
}

void MakeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
    if(main->right != nullptr)
    {
        delete main->right;
    }

    main->right = sub;
}

void PreOrderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
    if(bt == nullptr)
        return;

    action(bt->data);
    PreOrderTraverse(bt->left, action);
    PreOrderTraverse(bt->right, action);
}

void InOrderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
    if(bt == nullptr)
        return;

    InOrderTraverse(bt->left, action);
    action(bt->data);
    InOrderTraverse(bt->right, action);
}

void PostOrderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
    if(bt == nullptr)
        return;

    PostOrderTraverse(bt->left, action);
    PostOrderTraverse(bt->right, action);
    action(bt->data);
}

void DeleteTree(BTreeNode * bt)
{
    if(bt == nullptr)
        return;

    DeleteTree(bt->left);
    DeleteTree(bt->right);

    std::cout << "Delete tree data: " << bt->data << std:: endl;
    delete bt;
}

BTreeNode * RemoveLeftSubTree(BTreeNode * bt)
{
    BTreeNode * delNode = nullptr;
    if(bt != nullptr)
    {
        delNode = bt->left;
        bt->left = nullptr;
    }
    return delNode;
}

BTreeNode * RemoveRightSubTree(BTreeNode * bt)
{
    BTreeNode * delNode = nullptr;
    if(bt != nullptr)
    {
        delNode = bt->right;
        bt->right = nullptr;
    }
    return delNode;
}

void ChangeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{
    main->left = sub;
}

void ChangeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
    main->right = sub;
}