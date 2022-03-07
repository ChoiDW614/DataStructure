#include "ExpressionTree.h"
#include "ListBaseStack.h"
#include <string.h>
#include <cctype>
#include <iostream>

BTreeNode* MakeExpTree(const char exp[])
{
	Stack stack;
	BTreeNode* node;

	int expLen = strlen(exp);
	int i;

	StackInit(&stack);

	for (i = 0; i < expLen; i++)
	{
		node = MakeBTreeNode();
		if (isdigit(exp[i]))
		{
			SetData(node, exp[i] - '0');
		}
		else
		{
			SetData(node, exp[i]);
			MakeRightSubTree(node, SPop(&stack));
			MakeLeftSubTree(node, SPop(&stack));
		}
		SPush(&stack, node);
	}
	return SPop(&stack);
}

int EvaluateExpTree(BTreeNode* bt)
{
	if (GetLeftSubTree(bt) == nullptr && GetRightSubTree(bt) == nullptr)
		return GetData(bt);

	int op1, op2;

	op1 = EvaluateExpTree(GetLeftSubTree(bt));
	op2 = EvaluateExpTree(GetRightSubTree(bt));

	switch (GetData(bt))
	{
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	}
}

void ShowNodeData(int data)
{
	if (0 <= data && data <= 9)
		printf("%d ", data);
	else
		printf("%c ", data);
}

void ShowPrefixTypeExp(BTreeNode* bt)
{
	PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode* bt)
{
	if (bt == nullptr)
		return;
	
	if(bt->left != nullptr && bt->right != nullptr)
		printf(" ( ");

	ShowInfixTypeExp(bt->left);
	ShowNodeData(bt->data);
	ShowInfixTypeExp(bt->right);

	if (bt->left != nullptr && bt->right != nullptr)
		printf(" ) ");
}

void ShowPostfixTypeExp(BTreeNode* bt)
{
	PostorderTraverse(bt, ShowNodeData);
}
