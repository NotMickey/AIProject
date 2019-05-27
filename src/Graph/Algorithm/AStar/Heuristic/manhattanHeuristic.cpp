#include "manhattanHeuristic.h"

AIProject::Graph::ManhattanHeuristic::ManhattanHeuristic(const int & i_goalNode, const int &i_smallestEdgeCost, const DirectedWeightedGraph & i_graph) :
										m_goalNode(i_goalNode), m_smallestEdgeCost(i_smallestEdgeCost), m_graph(i_graph)
{}

int AIProject::Graph::ManhattanHeuristic::Estimate(const int & i_currentNode) const
{
	ofVec2f sourcePosition = m_graph.Localize(i_currentNode);
	ofVec2f goalPosition = m_graph.Localize(m_goalNode);

	int dx = abs(sourcePosition.x - goalPosition.x);
	int dy = abs(sourcePosition.y - goalPosition.y);

	return m_smallestEdgeCost * (dx + dy);
}
