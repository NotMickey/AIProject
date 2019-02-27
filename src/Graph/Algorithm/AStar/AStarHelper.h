#pragma once

#include "../../DataStructures/graphDataStructures.h"

namespace AIProject
{
	namespace Graph
	{
		//////
		/// A struct used during the A* algorithmic search process.
		/// It keeps track of a single node in the shortest node path.
		//////
		struct NodeRecord
		{
			NodeRecord() : node(0), costSoFar(0), estimatedTotalCost(0)
			{}

			NodeRecord(const int &i_node, const int &i_costSoFar, const int &i_estimatedTotalCost, const DirectedWeightedEdge &i_incomingEdge)
				: node(i_node), costSoFar(i_costSoFar), estimatedTotalCost(i_estimatedTotalCost), incomingEdge(i_incomingEdge)
			{}

			int node;
			int costSoFar; // g(x)
			int estimatedTotalCost; // h(x)
			DirectedWeightedEdge incomingEdge;
		};

		bool operator < (const NodeRecord &lhs, const NodeRecord &rhs);
		bool operator <= (const NodeRecord &lhs, const NodeRecord &rhs);

		bool operator > (const NodeRecord &lhs, const NodeRecord &rhs);
		bool operator >= (const NodeRecord &lhs, const NodeRecord &rhs);

		// These operators are slightly different as they compare the nodeID instead of g(x)

		bool operator == (const NodeRecord &lhs, const NodeRecord &rhs);
		bool operator != (const NodeRecord &lhs, const NodeRecord &rhs);

		class CloseList
		{
		public:
			std::vector<NodeRecord> list;

			bool Contains(const int &nodeID);
			NodeRecord Find(const int &nodeID);
			void Remove(const int &nodeID);
		};
	}
}