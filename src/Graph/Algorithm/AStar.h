#pragma once

#include <vector>

namespace AIProject
{
	namespace Graph
	{
		class DirectedWeightedGraph;
		class DirectedWeightedEdge;
		struct NodeRecord;

		class Heuristic
		{
		public:
			int Estimate(const int& i_node) const { return 0; } // for testing only !
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