#include <cstring>
#include <cctype>
#include <cstdio>
#include "ExpressionTree.h"
#include "ListBaseStack.h"

BTreeNode * MakeExpTree(char exp[])
{
    Stack stack;
    BTreeNode * pNode;

    int expLen = (int)strlen(exp);
    int i;

    StackInit(&stack);

    for(i = 0; i < expLen; i++)
    {
        pNode = MakeBTreeNode();

        if(isdigit(exp[i]))
        {
            SetData(pNode, exp[i]-'0');
        }
        else
        {
            MakeRightSubTree(pNode, SPop(&stack));
            MakeLeftSubTree(pNode, SPop(&stack));
            SetData(pNode, exp[i]);
        }

        SPush(&stack, pNode);
    }

    return SPop(&stack);
}

int EvaluateExpTree(BTreeNode * bt)
{
    int op1, op2;

    if(GetLeftSubTree(bt) == nullptr && GetRightSubTree(bt) == nullptr)
        return GetData(bt);

    op1 = EvaluateExpTree(GetLeftSubTree(bt));
    op2 = EvaluateExpTree(GetRightSubTree(bt));

    switch(GetData(bt))
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

    return 0;
}

void ShowNodeData(int data)
{
    if (0 <= data && data <= 9)
        printf("%d ", data);
    else
        printf("%c ", data);
}

void ShowPrefixTypeExp(BTreeNode * bt)
{
    PreOrderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode * bt)
{
    InOrderTraverse(bt, ShowNodeData);
}

void ShowPostfixTypeExp(BTreeNode * bt)
{
    PostOrderTraverse(bt, ShowNodeData);
}