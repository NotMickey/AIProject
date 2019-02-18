#pragma once

#include <vector>
#include "ofMain.h"

namespace AIProject
{
	namespace Graph
	{
		//////
		/// A class that defines a particular edge in a graph.
		//////
		class DirectedWeightedEdge
		{
		public:

			DirectedWeightedEdge(const int &i_sourceID = 0, const int &i_sinkID = 0, const int &i_edgeCost = 0)
				: m_sourceID(i_sourceID), m_sinkID(i_sinkID), m_edgeCost(i_edgeCost)
			{}

			/*DirectedWeightedEdge(const DirectedWeightedEdge &i_directedWeightedEdge)
				: m_sourceID(i_directedWeightedEdge.m_sourceID), m_sinkID(i_directedWeightedEdge.m_sinkID), m_edgeCost(i_directedWeightedEdge.m_edgeCost)
			{};*/

			inline int GetCost() const { return m_edgeCost; };
			inline int GetSource() const { return m_sourceID; };
			inline int GetSink() const { return m_sinkID; };

		private:

			int m_sourceID;
			int m_sinkID;
			int m_edgeCost;
		};

		class DirectedWeightedGraph
		{
		public:

			~DirectedWeightedGraph();

			std::vector<DirectedWeightedEdge> GetOutGoingEdges(const int &i_node) const;

			int AddNode(const ofVec2f &i_position);												// Add a new node and return its ID
			bool AddEdge(const int &i_sourceID, const int &i_sinkID, const int &i_edgeCost);    // Adds a new edge between given nodes if valid

			ofVec2f Localize(const int &i_nodeID) const;                                              // Returns world position of node

		private:

			std::vector<int> v_nodeList;
			std::vector<ofVec2f> v_positionList;
			std::vector<DirectedWeightedEdge> v_edgeList;
		};

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
	}
}