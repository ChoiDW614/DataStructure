#include <iostream>
#include <string.h>
#include "ALGraphDFS.h"
#include "ListBaseStack.h"

int WhoIsPrecede(LData d1, LData d2);

void GraphInit(ALGraph* pg, int nv)
{
	int i;

	pg->adjList = new List[nv];
	pg->visitInfo = new int[nv];

	pg->numV = nv;
	pg->numE = 0;

	for (i = 0; i < nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}
	memset(pg->visitInfo, 0, sizeof(int) * nv);
}

void GraphDestroy(ALGraph* pg)
{
	int i;
	LData data;

	for (i = 0; i < pg->numV; i++)
	{
		if (LFirst(&(pg->adjList[i]), &data)) {
			LRemove(&(pg->adjList[i]));
			while (LNext(&(pg->adjList[i]), &data))
			{
				LRemove(&(pg->adjList[i]));
			}
		}
	}

	if (pg->adjList != nullptr)
		delete[] pg->adjList;
	if (pg->visitInfo != nullptr)
		delete pg->visitInfo;
}

void AddEdge(ALGraph* pg, int fromV, int toV)
{
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;
}

void ShowGraphEdgeInfo(ALGraph* pg)
{
	int i;
	int vx;

	for (i = 0; i < pg->numV; i++)
	{
		std::cout << "vertex connect with " << (char)(i + 65) << ": ";
		if (LFirst(&(pg->adjList[i]), &vx)) {
			std::cout << (char)(vx + 65) << " ";

			while (LNext(&(pg->adjList[i]), &vx))
			{
				std::cout << (char)(vx + 65) << " ";
			}
			std::cout << '\n';
		}
	}
}

int VisitVertex(ALGraph* pg, int visitV)
{
	if (pg->visitInfo[visitV] == 0)
	{
		pg->visitInfo[visitV] = 1;
		std::cout << (char)(visitV + 65) << " ";
		return TRUE;
	}
	return false;
}

void DFShowGraphVertex(ALGraph* pg, int startV)
{
	Stack stack;
	int visitV = startV;
	int nextV;

	StackInit(&stack);
	VisitVertex(pg, visitV);
	SPush(&stack, visitV);

	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		int visitFlag = FALSE;

		if (VisitVertex(pg, nextV) == TRUE)
		{
			SPush(&stack, visitV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		else
		{
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
			{
				if (VisitVertex(pg, nextV) == TRUE)
				{
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}

		if (visitFlag == FALSE)
		{
			if (SIsEmpty(&stack) == TRUE)
				break;
			else
				visitV = SPop(&stack);
		}
	}

	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

int WhoIsPrecede(LData d1, LData d2)
{
	if (d1 < d2)
		return 0;
	else
		return 1;
}