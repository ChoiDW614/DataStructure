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

    plist->cur = plist->tail->next;
    plist->before = plist->tail;

    *pdata = plist->cur->data;
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