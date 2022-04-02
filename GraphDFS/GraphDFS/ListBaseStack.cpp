#include "ListBaseStack.h"
#include <iostream>
#include <cstdlib>

void StackInit(Stack* pstack)
{
	pstack->head = nullptr;
}

int SIsEmpty(Stack* pstack)
{
	if (pstack->head == nullptr)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data)
{
	Node_s* newNode = new Node_s;
	newNode->data = data;
	newNode->next = pstack->head;

	pstack->head = newNode;
}

Data SPop(Stack* pstack)
{
	Data rdata;
	Node_s* rnode;

	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}
	rdata = pstack->head->data;
	rnode = pstack->head;

	pstack->head = pstack->head->next;
	delete rnode;
	return rdata;
}

Data SPeek(Stack* pstack)
{
	if (SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->head->data;
}