#include <iostream>
#include <cstdlib>
#include "ListBaseStack.h"

void StackInit(Stack * pStack)
{
    pStack->head = nullptr;
}

int SIsEmpty(Stack * pStack)
{
    if(pStack->head == nullptr)
        return TRUE;
    else
        return FALSE;
}

void SPush(Stack * pStack, Data data)
{
    node * newNode = new Node;

    newNode->data = data;
    newNode->next = pStack->head;

    pStack->head = newNode;
}

Data SPop(Stack * pStack)
{
    Data rdata;
    Node * rNode;

    if(SIsEmpty(pStack))
    {
        std::cout << "Stack Memory Error" << std::endl;
        exit(-1);
    }

    rdata = pStack->head->data;
    rNode = pStack->head;

    pStack->head = pStack->head->next;
    delete rNode;
    return rdata;
}

Data SPeek(Stack * pStack)
{
    if(SIsEmpty(pStack))
    {
        std::cout << "Stack Memory Error" << std::endl;
        exit(-1);
    }

    return pStack->head->data;
}