#include "eulerHeuristic.h"

AIProject::Graph::EulerHeuristic::EulerHeuristic(const int & i_goalNode, const DirectedWeightedGraph & i_graph) :
								m_goalNode(i_goalNode), m_graph(i_graph)
{}

int AIProject::Graph::EulerHeuristic::Estimate(const int & i_currentNode) const
{
	ofVec2f sourcePosition = m_graph.Localize(i_currentNode);
	ofVec2f goalPosition = m_graph.Localize(m_goalNode);

	int heuristicEstimate = (int)sourcePosition.squareDistance(goalPosition);

	return heuristicEstimate;
}
