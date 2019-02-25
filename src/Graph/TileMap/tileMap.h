#pragma once

#include "../DataStructures/graphDataStructures.h"

namespace AIProject
{
	namespace Graph
	{
		class TileMap
		{
		public:
			TileMap(const int &i_totalLength, const int &i_tileLength, const ofVec2f &i_startPosition);

		private:
			float m_totalLength;
			float m_tileLength;
			float m_numOfTiles;

			ofVec2f m_startPosition;

			DirectedWeightedGraph m_graph;
		};
	}
}