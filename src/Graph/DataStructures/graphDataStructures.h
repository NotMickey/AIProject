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

			inline void SetCost(const int &i_newCost) { m_edgeCost = i_newCost; };

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
			bool InvalidateEdge(const int &i_sourceID, const int &i_sinkID);					// Sets cost of edge between given nodes to infinity (invalidates it)

			ofVec2f Localize(const int &i_nodeID) const;                                        // Returns world position of node

			void Draw();

		private:

			std::vector<int> v_nodeList;
			std::vector<ofVec2f> v_positionList;
			std::vector<DirectedWeightedEdge> v_edgeList;
		};
	}
}