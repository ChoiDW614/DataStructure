#include <iostream>
#include "DLinkedList.h"
#include "Table2.h"

void TBLInit(Table* pt, HashFunc f)
{
	int i;

	for (i = 0; i < MAX_TBL; i++)
		ListInit(&(pt->tbl[i]));

	pt->hf = *f;
}

void TBLInsert(Table* pt, Key k, Value v)
{
	int hv = pt->hf(k);
	Slot ns = { k, v };
	if (TBLSearch(pt, k) != nullptr)
	{
		std::cout << "key error \n";
		return;
	}
	else
	{
		LInsert(&(pt->tbl[hv]), ns);
	}
}

Value TBLDelete(Table* pt, Key k)
{
	int hv = pt->hf(k);
	Slot cSlot;

	if (LFirst(&(pt->tbl[hv]), &cSlot))
	{
		if (cSlot.key == k)
		{
			LRemove(&(pt->tbl[hv]));
			return cSlot.val;
		}
		else
		{
			while (LNext(&(pt->tbl[hv]), &cSlot))
			{
				if (cSlot.key == k)
				{
					LRemove(&(pt->tbl[hv]));
					return cSlot.val;
				}
			}
		}
	}

	return nullptr;
}

Value TBLSearch(Table* pt, Key k)
{
	int hv = pt->hf(k);
	Slot cSlot;

	if (LFirst(&(pt->tbl[hv]), &cSlot))
	{
		if (cSlot.key == k)
		{
			return cSlot.val;
		}
		else
		{
			while (LNext(&(pt->tbl[hv]), &cSlot))
			{
				if (cSlot.key == k)
				{
					return cSlot.val;
				}
			}
		}
	}

	return nullptr;
}