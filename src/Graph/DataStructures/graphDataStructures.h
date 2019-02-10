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

			DirectedWeightedEdge(const int &i_sourceID, const int &i_sinkID, const float &i_edgeCost)
				: m_sourceID(i_sourceID), m_sinkID(i_sinkID), m_edgeCost(i_edgeCost)
			{};

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

		// This class will need to be fleshed out more
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
			int node;
			DirectedWeightedEdge incomingEdge;

			int costSoFar; // g(x)
			int estimatedTotalCost; // h(x)
		};
	}
}