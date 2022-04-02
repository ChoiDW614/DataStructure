#include <iostream>
#include <string.h>
#include "ALGraphKruskal.h"
#include "ListBaseStack.h"

int WhoIsPrecede(LData d1, LData d2);
int PQWeightComp(Edge d1, Edge d2);

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

	PQueueInit(&(pg->pqueue), PQWeightComp);
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

void AddEdge(ALGraph* pg, int fromV, int toV, int weight)
{
	Edge edge = { fromV, toV, weight };

	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;

	PEnqueue(&(pg->pqueue), edge);
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
		// std::cout << (char)(visitV + 65) << " ";
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

void RemoveWayEdge(ALGraph* pg, int fromV, int toV)
{
	int edge;

	while (LFirst(&(pg->adjList[fromV]), &edge) == TRUE)
	{
		if (edge == toV)
		{
			LRemove(&(pg->adjList[fromV]));
			return;
		}
		else
		{
			while (LNext(&(pg->adjList[fromV]), &edge) == TRUE)
			{
				if (edge == toV)
				{
					LRemove(&(pg->adjList[fromV]));
					return;
				}
			}
		}
	}
}

void RemoveEdge(ALGraph* pg, int fromV, int toV)
{
	RemoveWayEdge(pg, fromV, toV);
	RemoveWayEdge(pg, toV, fromV);
	(pg->numE)--;
}

void RecoverEdge(ALGraph* pg, int fromV, int toV, int weight)
{
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	(pg->numE)++;
}

int IsConnVertex(ALGraph* pg, int v1, int v2)
{
	Stack stack;
	int visitV = v1;
	int nextV;

	StackInit(&stack);
	VisitVertex(pg, visitV);
	SPush(&stack, visitV);

	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		int visitFlag = FALSE;

		if (nextV == v2)
		{
			memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
			return TRUE;
		}

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
				if (nextV == v2)
				{
					memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
					return TRUE;
				}

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
	return FALSE;
}

void ConKruskalMST(ALGraph* pg)
{
	Edge recvEdge[20];
	Edge edge;
	int eidx = 0;
	int i;

	while (pg->numE + 1 > pg->numV)
	{
		edge = PDequeue(&(pg->pqueue));
		RemoveEdge(pg, edge.v1, edge.v2);

		if (!IsConnVertex(pg, edge.v1, edge.v2))
		{
			RecoverEdge(pg, edge.v1, edge.v2, edge.weight);
			recvEdge[eidx++] = edge;
		}
	}

	for (i = 0; i < eidx; i++)
		PEnqueue(&(pg->pqueue), recvEdge[i]);
}

void ShowGraphEdgeWeightInfo(ALGraph* pg)
{
	PQueue copyPQ = pg->pqueue;
	Edge edge;

	while (!PQIsEmpty(&copyPQ))
	{
		edge = PDequeue(&copyPQ);
		std::cout << "(" << (char)(edge.v1 + 65) << "-" << (char)(edge.v2 + 65) << "), w: " << edge.weight << '\n';
	}
}

int WhoIsPrecede(LData d1, LData d2)
{
	if (d1 < d2)
		return 0;
	else
		return 1;
}

int PQWeightComp(Edge d1, Edge d2)
{
	return d1.weight - d2.weight;
}