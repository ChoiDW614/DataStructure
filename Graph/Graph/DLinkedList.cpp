#include "DLinkedList.h"

void ListInit(List* plist)
{
	plist->head = new Node;
	plist->head->next = nullptr;
	plist->numOfData = 0;
	plist->comp = nullptr;
}

void FInsert(List* plist, LData data)
{
	Node* newNode = new Node;
	newNode->data = data;

	newNode->next = plist->head->next;
	plist->head->next = newNode;

	(plist->numOfData)++;
}

void SInsert(List* plist, LData data)
{
	Node* newNode = new Node;
	Node* pred = plist->head;
	newNode->data = data;

	while (pred->next != nullptr && plist->comp(data, pred->next->data) != 0)
	{
		pred = pred->next;
	}
	newNode->next = pred->next;
	pred->next = newNode;
	(plist->numOfData)++;
}

void LInsert(List* plist, LData data)
{
	if (plist->comp == nullptr)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}

int LFirst(List* plist, LData* pdata)
{
	if (plist->head->next == nullptr)
		return FALSE;

	plist->before = plist->head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, LData* pdata)
{
	if (plist->cur->next == nullptr)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List* plist)
{
	Node* rpos = plist->cur;
	LData rdata = plist->cur->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	delete rpos;
	(plist->numOfData)--;
	return rdata;
}

int LCount(List* plist)
{
	return plist->numOfData;
}

int WhoIsPrecede(LData d1, LData d2)
{
	if (d1 < d2)
		return 0;
	else
		return 1;
}

void SetSortRule(List* plist, int (*comp)(LData d1, LData d2))
{
	plist->comp = comp;
}