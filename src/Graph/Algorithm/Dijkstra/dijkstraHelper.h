#pragma once

#include "../../DataStructures/graphDataStructures.h"

namespace AIProject
{
	namespace Graph
	{
		//////
		/// A struct used during the Dijkstra algorithmic search process.
		/// It keeps track of a single node in the shortest node path.
		//////
		struct NodeRecordDijkstra
		{
			NodeRecordDijkstra() : node(0), costSoFar(0)
			{}

			NodeRecordDijkstra(const int &i_node, const int &i_costSoFar, const DirectedWeightedEdge &i_incomingEdge)
				: node(i_node), costSoFar(i_costSoFar), incomingEdge(i_incomingEdge)
			{}

			int node;
			int costSoFar; // g(x)
			DirectedWeightedEdge incomingEdge;
		};

		bool operator < (const NodeRecordDijkstra &lhs, const NodeRecordDijkstra &rhs);
		bool operator <= (const NodeRecordDijkstra &lhs, const NodeRecordDijkstra &rhs);

		bool operator > (const NodeRecordDijkstra &lhs, const NodeRecordDijkstra &rhs);
		bool operator >= (const NodeRecordDijkstra &lhs, const NodeRecordDijkstra &rhs);

		// These operators are slightly different as they compare the nodeID instead of g(x)

		bool operator == (const NodeRecordDijkstra &lhs, const NodeRecordDijkstra &rhs);
		bool operator != (const NodeRecordDijkstra &lhs, const NodeRecordDijkstra &rhs);

		class CloseListDijkstra
		{
		public:
			std::vector<NodeRecordDijkstra> list;

			bool Contains(const int &nodeID);

			NodeRecordDijkstra Find(const int &nodeID);

			void Remove(const int &nodeID);
		};
	}
}