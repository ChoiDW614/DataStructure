#include <iostream>
#include <cstdio>
#include "ListBaseQueue.h"

void QueueInit(Queue* pq)
{
	pq->front = nullptr;
	pq->rear = nullptr;
}

int QIsEmpty(Queue* pq)
{
	if (pq->front == nullptr)
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue* pq, Data data)
{
	Node* newNode = new Node;
	newNode->next = nullptr;
	newNode->data = data;

	if (QIsEmpty(pq))
	{
		pq->front = newNode;
		pq->rear = newNode;
	}
	else
	{
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
}

Data Dequeue(Queue* pq)
{
	Node* rNode = pq->front;
	Data rdata = pq->front->data;

	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}
	pq->front = pq->front->next;

	delete rNode;
	return rdata;
}

Data QPeek(Queue* pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}
	return pq->front->data;
}