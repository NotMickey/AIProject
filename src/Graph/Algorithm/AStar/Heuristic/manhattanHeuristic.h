#pragma once

#include "heuristic.h"
#include "../../../DataStructures/graphDataStructures.h"

namespace AIProject
{
	namespace Graph
	{
		class ManhattanHeuristic : public Heuristic
		{
		public:
			ManhattanHeuristic(const int &i_goalNode, const int &i_smallestEdgeCost,const DirectedWeightedGraph &i_graph);

			int Estimate(const int& i_currentNode) const override;

		private:
			int m_goalNode;
			int m_smallestEdgeCost;
			DirectedWeightedGraph m_graph;
		};
	}
}