#ifndef __LIST_BASE_QUEUE_H__
#define __LIST_BASE_QUEUE_H__

constexpr int TRUE  =        1;
constexpr int FALSE =       0;

typedef int Data;

typedef class node
{
public:
    Data data;
    node * next;
}Node;

typedef class lQueue
{
public:
    Node * front;
    Node * rear;
}LQueue;

typedef LQueue Queue;

void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);

void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);

#endif //__LIST_BASE_QUEUE_H__
