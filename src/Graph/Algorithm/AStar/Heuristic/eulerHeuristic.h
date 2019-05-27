#pragma once

#include "heuristic.h"
#include "../../../DataStructures/graphDataStructures.h"

namespace AIProject
{
	namespace Graph
	{
		class EulerHeuristic : public Heuristic
		{
		public:
			EulerHeuristic(const int &i_goalNode, const DirectedWeightedGraph &i_graph);

			int Estimate(const int& i_currentNode) const override;

		private:
			int m_goalNode;
			DirectedWeightedGraph m_graph;
		};
	}
}