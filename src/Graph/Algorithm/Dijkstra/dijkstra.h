#pragma once

#include <vector>
#include "../../DataStructures/graphDataStructures.h"

namespace AIProject
{
	namespace Graph
	{
		// return value will be a path
		std::vector<DirectedWeightedEdge> FindPath(const int &i_start, const int &i_goal, const DirectedWeightedGraph& i_graph);
	}
}
