#pragma once

#include "../DataStructures/graphDataStructures.h"

namespace AIProject
{
	namespace Graph
	{
		class TileMap
		{
		public:
			TileMap(int i_numOfTilesPerSide, int i_tileLength, float i_edgeCost, const ofVec2f &i_startPosition);

			DirectedWeightedGraph GetGraph();

			int GetNodeAtPosition(const ofVec2f &i_position) const;
			inline int GetNumberOfTilesPerSide() const { return m_numOfTilesPerSide; }

			void Draw();

		private:
			int m_numOfTilesPerSide;
			float m_tileLength;

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