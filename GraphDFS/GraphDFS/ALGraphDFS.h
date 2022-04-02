#ifndef __AL_GRAPH_DFS__
#define __AL_GRAPH_DFS__

#include "DLinkedList.h"

enum class vertex { A, B, C, D, E, F, G, H, I, J };

class ALGraph
{
public:
	int numV;
	int numE;
	List* adjList;
	int* visitInfo;
};

void GraphInit(ALGraph* pg, int nv);

void GraphDestroy(ALGraph* pg);

void AddEdge(ALGraph* pg, int fromV, int toV);

void ShowGraphEdgeInfo(ALGraph* pg);

void DFShowGraphVertex(ALGraph* pg, int startV);

#endif