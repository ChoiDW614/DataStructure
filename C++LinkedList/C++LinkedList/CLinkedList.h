#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

constexpr auto TRUE = 1;
constexpr auto FALSE = 0;

typedef int Data;

typedef class node
{
public:
    Data data;
    node * next;
}Node;

typedef class CLL
{
public:
    Node * tail;
    Node * cur;
    Node * before;
    int numOfData;
}CList;

typedef CList List;

void ListInit(List * plist);
void LInsert(List * plist, Data data);          // add node to tail
void LInsertFront(List * plist, Data data);     // add node to head

int LFirst(List * plist, Data * pdata);
int LNext(List * plist, Data * pdata);
Data LRemove(List * plist);
int LCount(List * plist);

#endif