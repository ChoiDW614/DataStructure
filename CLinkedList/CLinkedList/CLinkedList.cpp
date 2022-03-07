#include "CLinkedList.h"

void ListInit(List* plist)
{
	plist->tail = nullptr;
	plist->cur = nullptr;
	plist->before = nullptr;
	plist->numOfData = 0;
}

void LInsert(List* plist, Data data)
{
	Node* newNode = new Node;
	newNode->data = data;

	if (plist->tail == nullptr)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;
	}
	(plist->numOfData)++;
}

void LInsertFront(List* plist, Data data)
{
	Node* newNode = new Node;
	newNode->data = data;

	if (plist->tail == nullptr)
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

int LFirst(List* plist, Data* pdata)
{
	if (plist->tail == nullptr)
		return FALSE;

	plist->before = plist->tail;
	plist->cur = plist->tail->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, Data* pdata)
{
	if (plist->tail == nullptr)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

Data LRemove(List* plist)
{
	Node* tmpNode = plist->cur;
	Data tmpData = tmpNode->data;

	if (plist->cur == plist->tail)
	{
		if (plist->tail == plist->tail->next)
		{
			plist->tail = nullptr;
		}
		else
		{
			plist->tail = plist->before;
		}
	}
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	delete tmpNode;
	(plist->numOfData)--;
	return tmpData;
}

int LCount(List* plist)
{
	return plist->numOfData;
}