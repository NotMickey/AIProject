#pragma once

#include "../DataStructures/graphDataStructures.h"

namespace AIProject
{
	namespace Graph
	{
		// return value will be a path
		void FindPath(const int &i_start, const int &i_goal, const DirectedWeightedGraph& i_graph /*, heuristic class here*/ )
		{
			DirectedWeightedEdge edge;
			NodeRecord startRecord(i_start, 0, 12, edge);
		}
	}
}