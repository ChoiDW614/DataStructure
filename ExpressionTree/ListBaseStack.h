#ifndef __LIST_BASE_STACK_H__
#define __LIST_BASE_STACK_H__

constexpr int TRUE = 1;
constexpr int FALSE = 0;

typedef int Data;

typedef class node
{
public:
    Data data;
    node * next;
}Node;

typedef class listStack
{
public:
    Node * head;
}ListStack;

typedef ListStack Stack;

void StackInit(Stack * pStack);
int SIsEmpty(Stack * pStack);

void SPush(Stack * pStack, Data data);
Data SPop(Stack * pStack);
Data SPeek(Stack * pStack);

#endif