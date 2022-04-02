#include <iostream>
#include "ALGraph.h"

int main()
{
	ALGraph graph;
	GraphInit(&graph, 5);

	AddEdge(&graph, (int)vertex::A, (int)vertex::B);
	AddEdge(&graph, (int)vertex::A, (int)vertex::D);
	AddEdge(&graph, (int)vertex::B, (int)vertex::C);
	AddEdge(&graph, (int)vertex::C, (int)vertex::D);
	AddEdge(&graph, (int)vertex::D, (int)vertex::E);
	AddEdge(&graph, (int)vertex::E, (int)vertex::A);

	ShowGraphEdgeInfo(&graph);
	GraphDestory(&graph);
	int a;
	return 0;
}