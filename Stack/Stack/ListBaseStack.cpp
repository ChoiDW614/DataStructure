#include <iostream>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack * pstack)
{
    pstack->head = NULL;
}

int SIsEmpty(Stack * pstack)
{
    if (pstack->head == NULL)
        return TRUE;
    else
        return FALSE;
}

void SPush(Stack * pstack, Data data)
{
    Node * newNode = new Node;
    newNode->data = data;
    newNode->next = pstack->head;

    pstack->head = newNode;
}

Data SPop(Stack * pstack)
{
    Data rdata;
    Node * rnode;

    if (SIsEmpty(pstack))
    {
        std::cout << "stack memory error" << std::endl;
        exit(-1);
    }
    rdata = pstack->head->data;
    rnode = pstack->head;

    pstack->head = pstack->head->next;
    delete rnode;
    return rdata;
}

Data SPeek(Stack * pstack)
{
    if (SIsEmpty(pstack))
    {
        std::cout << "stack memory error" << std::endl;
        exit(-1);
    }

    return pstack->head->data;
}