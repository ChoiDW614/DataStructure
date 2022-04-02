#include <iostream>
#include "ALGraphDFS.h"

int main()
{
	ALGraph graph;
	GraphInit(&graph, 7);

	AddEdge(&graph, (int)vertex::A, (int)vertex::B);
	AddEdge(&graph, (int)vertex::A, (int)vertex::D);
	AddEdge(&graph, (int)vertex::B, (int)vertex::C);
	AddEdge(&graph, (int)vertex::D, (int)vertex::C);
	AddEdge(&graph, (int)vertex::D, (int)vertex::E);
	AddEdge(&graph, (int)vertex::E, (int)vertex::F);
	AddEdge(&graph, (int)vertex::E, (int)vertex::G);

	ShowGraphEdgeInfo(&graph);

	DFShowGraphVertex(&graph, (int)vertex::A); std::cout << '\n';
	DFShowGraphVertex(&graph, (int)vertex::C); std::cout << '\n';
	DFShowGraphVertex(&graph, (int)vertex::E); std::cout << '\n';
	DFShowGraphVertex(&graph, (int)vertex::G); std::cout << '\n';

	GraphDestroy(&graph);
	return 0;
}