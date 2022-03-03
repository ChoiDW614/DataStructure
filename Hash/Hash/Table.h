#ifndef __TABLE_H__
#define __TABLE_H__

#include "Slot.h"

#define MAX_TBL		100

typedef int (*HashFunc)(Key k);

typedef struct _table
{
	Slot tbl[MAX_TBL];
	int (*hf)(int);
}Table;

void TBLInit(Table* pt, int (*f)(int));
void TBLInsert(Table* pt, Key k, Value v);
Value TBLDelete(Table* pt, Key k);
Value TBLSearch(Table* pt, Key k);

#endif