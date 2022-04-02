#include <iostream>
#include "ALGraph.h"
#include "DLinkedList.h"

void GraphInit(ALGraph* pg, int nv)
{
	int i;

	pg->adjList = new List[nv];
	
	pg->numV = nv;
	pg->numE = 0;

	for (i = 0; i < nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}
}

void GraphDestory(ALGraph* pg)
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