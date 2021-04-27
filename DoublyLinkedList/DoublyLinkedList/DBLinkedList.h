#ifndef __DB_LINKED_LIST_H__
#define __DB_LINKED_LIST_H__

constexpr int TRUE = 1;
constexpr int FALSE = 0;

typedef int Data;

typedef class node
{
public:
    Data data;
    node * next;
    node * prev;
}Node;

typedef class DLinkedList
{
public:
    node * head;
    node * cur;
    int numOfData;
}DBLinkedList;

typedef DBLinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, Data data);

int LFirst(List * plist, Data * pdata);
int LNext(List * plist, Data * pdata);
int LPrevious(List * plist, Data * pdata);

int LCount(List * plist);

#endif