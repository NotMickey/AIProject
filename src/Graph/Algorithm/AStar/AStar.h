#pragma once

#include <vector>

namespace AIProject
{
	namespace Graph
	{
		class Heuristic;
		class DirectedWeightedGraph;
		class DirectedWeightedEdge;

		// return value will be a path
		std::vector<DirectedWeightedEdge> FindPath(const int &i_start, const int &i_goal, const DirectedWeightedGraph& i_graph, const Heuristic &i_heuristic);
	}
}