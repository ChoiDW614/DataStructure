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

void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);

void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);

#endif