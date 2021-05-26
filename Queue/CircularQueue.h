#ifndef __CIRCULAR_QUEUE_H__
#define __CIRCULAR_QUEUE_H__

constexpr int TRUE =        1;
constexpr int FALSE =       0;

constexpr int QUE_LEN =     100;
typedef int Data;

typedef class cQueue
{
public:
    int front;
    int rear;
    Data queArr[QUE_LEN];
}CQueue;

typedef CQueue Queue;

void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);

void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);

#endif
