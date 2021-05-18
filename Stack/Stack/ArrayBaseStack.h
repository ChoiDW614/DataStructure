#ifndef __ARRAY_BASE_STACK_H__
#define __ARRAY_BASE_STACK_H__

constexpr int TRUE      = 1;
constexpr int FALSE     = 0;
constexpr int STACK_LEN = 100;

typedef int Data;

typedef class arrayStack
{
public:
    Data stackArr[STACK_LEN];
    int topIndex;
}ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack * pstack);             // initialize stack
int SIsEmpty(Stack * pstack);               // check if the stack is empty

void SPush(Stack * pstack, Data data);      // stack Push opertaion
Data SPop(Stack * pstack);                  // stack Pop opertaion
Data SPeek(Stack * pstack);                 // stack Peek opertaion

#endif