#pragma once

#include "../DataStructures/graphDataStructures.h"

namespace AIProject
{
	namespace Graph
	{
		class TileMap
		{
		public:
			TileMap(const int &i_numOfTilesPerSide, const int &i_tileLength, const float &i_edgeCost,const ofVec2f &i_startPosition);

			DirectedWeightedGraph GetGraph();

			int GetNodeFromMouseClick(const ofVec2f &i_position);

		private:
			float m_tileLength;
			float m_numOfTilesPerSide;

			float m_edgeCost;

			ofVec2f m_startPosition;

			DirectedWeightedGraph m_graph;

			void BuildGraph();

			void AddNodes();
			void AddEdges();

			bool IsEdgeTile(const int &i_row, const int &i_column);
			bool IsCornerTile(const int &i_row, const int &i_column);
		};
	}
}