#include <iostream>
#include "ALGraphKruskal.h"

int main()
{
	ALGraph graph;
	GraphInit(&graph, 6);

	AddEdge(&graph, (int)vertex::A, (int)vertex::B, 9);
	AddEdge(&graph, (int)vertex::B, (int)vertex::C, 2);
	AddEdge(&graph, (int)vertex::A, (int)vertex::C, 12);
	AddEdge(&graph, (int)vertex::A, (int)vertex::D, 8);
	AddEdge(&graph, (int)vertex::D, (int)vertex::C, 6);
	AddEdge(&graph, (int)vertex::A, (int)vertex::F, 11);
	AddEdge(&graph, (int)vertex::F, (int)vertex::D, 4);
	AddEdge(&graph, (int)vertex::D, (int)vertex::E, 3);
	AddEdge(&graph, (int)vertex::E, (int)vertex::C, 7);
	AddEdge(&graph, (int)vertex::F, (int)vertex::E, 13);

	ConKruskalMST(&graph);
	ShowGraphEdgeInfo(&graph);
	ShowGraphEdgeWeightInfo(&graph);

	GraphDestroy(&graph);
	return 0;
}