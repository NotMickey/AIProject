#include "tileMap.h"

AIProject::Graph::TileMap::TileMap(const int & i_totalLength, const int & i_tileLength, const ofVec2f &i_startPosition) :
						m_totalLength(i_totalLength), m_tileLength(i_tileLength), m_startPosition(i_startPosition)
{
	m_numOfTiles = i_totalLength / i_tileLength;
}
