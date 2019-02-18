#pragma once

#include <vector>
#include "../DataStructures/graphDataStructures.h"

namespace AIProject
{
	namespace Graph
	{
		class Heuristic
		{
		public:

			Heuristic(const int &i_goalNode, const DirectedWeightedGraph &i_graph) : m_graph(i_graph), m_goalNode(i_goalNode)
			{}

			int Estimate(const int& i_currentNode) const;

		private:

			int m_goalNode;
			DirectedWeightedGraph m_graph;
		};

		class CloseList
		{
		public:
			std::vector<NodeRecord> list;

			bool Contains(const int &nodeID);

			NodeRecord Find(const int &nodeID);

			void Remove(const int &nodeID);
		};

		// return value will be a path
		std::vector<DirectedWeightedEdge> FindPath(const int &i_start, const int &i_goal, const DirectedWeightedGraph& i_graph, const Heuristic &i_heuristic);
	}
}