#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include "BinaryTree.h"

BTreeNode * MakeExpTree(char exp[]);        // Formula tree configuration
int EvaluateExpTree(BTreeNode * bt);        // Calculate formula tree

void ShowPrefixTypeExp(BTreeNode * bt);
void ShowInfixTypeExp(BTreeNode * bt);
void ShowPostfixTypeExp(BTreeNode * bt);

#endif //__EXPRESSION_TREE_H__