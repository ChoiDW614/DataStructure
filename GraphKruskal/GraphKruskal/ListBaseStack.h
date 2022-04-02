#ifndef __LB_STACK_H__
#define __LB_STACK_H__

#define TRUE	1
#define FALSE	0

typedef int Data;

typedef struct _node_s
{
	Data data;
	struct _node_s* next;
}Node_s;

typedef struct _listStack_s
{
	Node_s* head;
}ListStack_s;

typedef ListStack_s Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);

#endif