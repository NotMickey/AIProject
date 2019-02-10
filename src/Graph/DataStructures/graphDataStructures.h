#pragma once

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

			DirectedWeightedEdge(const int &i_sourceID = 0, const int &i_sinkID = 0, const float &i_edgeCost = 0)
				: m_sourceID(i_sourceID), m_sinkID(i_sinkID), m_edgeCost(i_edgeCost)
			{}

			/*DirectedWeightedEdge(DirectedWeightedEdge &i_directedWeightedEdge)
				: m_sourceID(i_directedWeightedEdge.m_sourceID), m_sinkID(i_directedWeightedEdge.m_sinkID), m_edgeCost(i_directedWeightedEdge.m_edgeCost)
			{};*/

			inline float GetCost() { return m_edgeCost; };
			inline int GetSource() { return m_sourceID; };
			inline int GetSink() { return m_sinkID; };

		private:

			int m_sourceID;
			int m_sinkID;
			float m_edgeCost;
		};

		// This class will need to be fleshed out more - TODO
		class DirectedWeightedGraph
		{
		public:

			void GetOutGoingEdges(const int &node);

		private:

			//DirectedWeightedEdge

		};

		//////
		/// A struct used during the A* algorithmic search process.
		/// It keep track of a single node in the shortest node path.
		//////
		struct NodeRecord
		{
			NodeRecord(const int &i_node, const int &i_costSoFar, const int &i_estimatedTotalCost, const DirectedWeightedEdge &i_incomingEdge)
				: node(i_node), costSoFar(i_costSoFar), estimatedTotalCost(i_estimatedTotalCost), incomingEdge(i_incomingEdge)
			{}

			int node;
			
			int costSoFar; // g(x)
			int estimatedTotalCost; // h(x)

			DirectedWeightedEdge incomingEdge;
		};
	}
}