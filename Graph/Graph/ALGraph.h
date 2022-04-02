#ifndef __AL_GRAPH__
#define __AL_GRAPH__

#include "DLinkedList.h"

enum class vertex{A, B, C, D, E, F, G, H, I, J};

class ALGraph
{
public:
	int numV;
	int numE;
	List* adjList;
};

void GraphInit(ALGraph* pg, int nv);

void GraphDestory(ALGraph* pg);

void AddEdge(ALGraph* pg, int fromV, int toV);

void ShowGraphEdgeInfo(ALGraph* pg);

#endif