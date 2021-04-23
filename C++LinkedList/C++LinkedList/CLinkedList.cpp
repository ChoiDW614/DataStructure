#include <iostream>
#include "CLinkedList.h"
using namespace std;

void ListInit(List * plist)     // initialize the list
{
    plist->tail = NULL;
    plist->cur = NULL;
    plist->before = NULL;
    plist->numOfData = 0;
}

void LInsert(List * plist, Data data)
{
    Node * newNode = new Node;
    newNode->data = data;

    if (plist->tail == NULL)            // if tail is empty
    {
        plist->tail = newNode;          // tail indicate newnode
        newNode->next = newNode;        // newNode indicate itself
    }
    else
    {

    }

    (plist->numOfData)++;
}