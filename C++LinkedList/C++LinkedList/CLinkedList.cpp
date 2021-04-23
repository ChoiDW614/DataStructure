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
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
        plist->tail = newNode;      // different from LInsertFront
    }

    (plist->numOfData)++;
}

void LInsertFront(List * plist, Data data)
{
    Node * newNode = new Node;
    newNode->data = data;

    if (plist->tail == NULL)        // same as Linsert
    {
        plist->tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
    }

    (plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
    if (plist->tail == NULL)
        return FALSE;

    plist->cur = plist->tail->next;     // cur refer to head
    plist->before = plist->tail;        // before refer to tail

    *pdata = plist->cur->data;          // return data of cur
    return TRUE;
}

int LNext(List * plist, Data * data)
{
    if (plist->tail == NULL)
        return FALSE;

    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *data = plist->cur->data;
    return TRUE;
}

Data LRemove(List * plist)
{
    if (plist->tail == NULL)
        return FALSE;

    int temp = plist->cur->data;
    plist->before->next = plist->cur->next;
    plist->cur = plist->before;



    
}