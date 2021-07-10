#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef class bTreeNode
{
public:
    BTData data;
    bTreeNode * left;
    bTreeNode * right;
}BTreeNode;

BTreeNode * MakeBTreeNode();
BTData GetData(BTreeNode * bt);
void SetData(BTreeNode * bt, BTData data);

BTreeNode * GetLeftSubTree(BTreeNode * bt);
BTreeNode * GetRightSubTree(BTreeNode * bt);

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub);
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub);

typedef void (*VisitFuncPtr)(BTData data);

void PreOrderTraverse(BTreeNode * bt, VisitFuncPtr action);
void InOrderTraverse(BTreeNode * bt, VisitFuncPtr action);
void PostOrderTraverse(BTreeNode * bt, VisitFuncPtr action);

void DeleteTree(BTreeNode * bt);

BTreeNode * RemoveLeftSubTree(BTreeNode * bt);
BTreeNode * RemoveRightSubTree(BTreeNode * bt);
void ChangeLeftSubTree(BTreeNode * main, BTreeNode * sub);
void ChangeRightSubTree(BTreeNode * main, BTreeNode * sub);

#endif //__BINARY_TREE_H__