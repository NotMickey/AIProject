#include "tileMap.h"

AIProject::Graph::TileMap::TileMap(const int & i_numOfTilesPerSide, const int & i_tileLength, const float & i_edgeCost, const ofVec2f &i_startPosition) :
						m_numOfTilesPerSide(i_numOfTilesPerSide), m_tileLength(i_tileLength), m_edgeCost(i_edgeCost), m_startPosition(i_startPosition)
{
	BuildGraph();
}

AIProject::Graph::DirectedWeightedGraph AIProject::Graph::TileMap::GetGraph()
{
	return m_graph;
}

int AIProject::Graph::TileMap::GetNodeFromMouseClick(const ofVec2f &i_position)
{
	if (i_position.x < m_startPosition.x || i_position.x > m_startPosition.x + m_numOfTilesPerSide * m_tileLength)
		return -1;

	if (i_position.y < m_startPosition.y || i_position.y > m_startPosition.y + m_numOfTilesPerSide * m_tileLength)
		return -1;

	float xDist = i_position.x - m_startPosition.x;
	
	int column = 0;

	while (column * m_tileLength < xDist)
	{
		if (m_tileLength * (column + 1) > xDist)
			break;

		column++;
	}

	float yDist = i_position.y - m_startPosition.y;

	int row = 0;

	while (row * m_tileLength < yDist)
	{
		if (m_tileLength * (row + 1) > xDist)
			break;

		row++;
	}
		
	// At this point I have the row and column numbers

	int nodeID = m_numOfTilesPerSide * row + column;

	return nodeID;
}

void AIProject::Graph::TileMap::BuildGraph()
{
	AddNodes();

	AddEdges();
}

void AIProject::Graph::TileMap::AddNodes()
{
	float tileHalfLength = m_tileLength / 2;

	for (int i = 0; i < m_numOfTilesPerSide; i++)
	{
		for (int j = 0; j < m_numOfTilesPerSide; j++)
		{
			ofVec2f position;
			position.y = m_startPosition.y + m_tileLength * i + tileHalfLength;
			position.x = m_startPosition.x + m_tileLength * j + tileHalfLength;

			m_graph.AddNode(position);
		}
	}
}

void AIProject::Graph::TileMap::AddEdges()
{
	for (int i = 0; i < m_numOfTilesPerSide; i++)
	{
		for (int j = 0; j < m_numOfTilesPerSide; j++)
		{
			if (IsEdgeTile(i, j))
			{
				if (IsCornerTile(i, j))
				{
					if (i == 0)
					{
						m_graph.AddEdge(i, m_numOfTilesPerSide * (i + 1), m_edgeCost);

						if (j == 0)
							m_graph.AddEdge(j, j + 1, m_edgeCost);
						else
							m_graph.AddEdge(j, j - 1, m_edgeCost);
					}
					else
					{
						m_graph.AddEdge(i, m_numOfTilesPerSide * (i - 1), m_edgeCost);

						if (j == 0)
							m_graph.AddEdge(m_numOfTilesPerSide * i, m_numOfTilesPerSide * i + 1, m_edgeCost);
						else
							m_graph.AddEdge(m_numOfTilesPerSide * i + j, m_numOfTilesPerSide * i + j - 1, m_edgeCost);
					}
				}
				else
				{
					if (j > 0 && j < m_numOfTilesPerSide - 1)
					{
						m_graph.AddEdge(m_numOfTilesPerSide * i + j, m_numOfTilesPerSide * i + j + 1, m_edgeCost);
						m_graph.AddEdge(m_numOfTilesPerSide * i + j, m_numOfTilesPerSide * i + j - 1, m_edgeCost);

						if (i == 0)
							m_graph.AddEdge(m_numOfTilesPerSide * i + j, m_numOfTilesPerSide * (i + 1) + j, m_edgeCost);
						else
							m_graph.AddEdge(m_numOfTilesPerSide * i + j, m_numOfTilesPerSide * (i - 1) + j, m_edgeCost);
					}
					else
					{
						m_graph.AddEdge(m_numOfTilesPerSide * i + j, m_numOfTilesPerSide * (i + 1) + j, m_edgeCost);
						m_graph.AddEdge(m_numOfTilesPerSide * i + j, m_numOfTilesPerSide * (i - 1) + j, m_edgeCost);

						if (j == 0)
							m_graph.AddEdge(m_numOfTilesPerSide * i + j, m_numOfTilesPerSide * i + j + 1, m_edgeCost);
						else
							m_graph.AddEdge(m_numOfTilesPerSide * i + j, m_numOfTilesPerSide * i + j - 1, m_edgeCost);
					}
				}
			}
			else
			{
				m_graph.AddEdge(m_numOfTilesPerSide * i + j, m_numOfTilesPerSide * (i + 1) + j, m_edgeCost);
				m_graph.AddEdge(m_numOfTilesPerSide * i + j, m_numOfTilesPerSide * (i - 1) + j, m_edgeCost);

				m_graph.AddEdge(m_numOfTilesPerSide * i + j, m_numOfTilesPerSide * i + j + 1, m_edgeCost);
				m_graph.AddEdge(m_numOfTilesPerSide * i + j, m_numOfTilesPerSide * i + j - 1, m_edgeCost);
			}
		}
	}
}

bool AIProject::Graph::TileMap::IsEdgeTile(const int & i_row, const int & i_column)
{
	if (i_row == 0 || i_row == m_numOfTilesPerSide - 1)
		return true;

	if (i_column == 0 || i_column == m_numOfTilesPerSide - 1)
		return true;

	return false;
}

bool AIProject::Graph::TileMap::IsCornerTile(const int & i_row, const int & i_column)
{
	// top left
	if (i_row == 0 && i_column == 0)
		return true;

	// top right
	if (i_row == 0 && i_column == m_numOfTilesPerSide - 1)
		return true;

	// bottom left
	if (i_row == m_numOfTilesPerSide - 1 && i_column == 0)
		return true;

	// bottom right
	if (i_row == m_numOfTilesPerSide - 1 && i_column == m_numOfTilesPerSide - 1)
		return true;

	return false;
}
