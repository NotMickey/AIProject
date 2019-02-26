#include "AStarHelper.h"

int AIProject::Graph::Heuristic::Estimate(const int & i_currentNode) const
{
	ofVec2f sourcePosition = m_graph.Localize(i_currentNode);
	ofVec2f goalPosition = m_graph.Localize(m_goalNode);

	int heuristicEstimate = (int)sourcePosition.squareDistance(goalPosition);

	return heuristicEstimate;
}

bool AIProject::Graph::CloseList::Contains(const int & nodeID)
{
	for (size_t i = 0; i < list.size(); i++)
	{
		if (list[i].node == nodeID)
			return true;
	}

	return false;
}

AIProject::Graph::NodeRecord AIProject::Graph::CloseList::Find(const int & nodeID)
{
	for (size_t i = 0; i < list.size(); i++)
	{
		if (list[i].node == nodeID)
			return list[i];
	}

	return NodeRecord();
}

void AIProject::Graph::CloseList::Remove(const int & nodeID)
{
	for (size_t i = 0; i < list.size(); i++)
	{
		if (list[i].node == nodeID)
		{
			using std::swap;

			swap(list[i], list.back());
			list.pop_back();
		}
	}
}

bool AIProject::Graph::operator < (const NodeRecord &lhs, const NodeRecord &rhs) { if (lhs.estimatedTotalCost < rhs.estimatedTotalCost) return true; return false; }
bool AIProject::Graph::operator <= (const NodeRecord &lhs, const NodeRecord &rhs) { if (lhs.estimatedTotalCost <= rhs.estimatedTotalCost) return true; return false; }

bool AIProject::Graph::operator > (const NodeRecord &lhs, const NodeRecord &rhs) { return !(lhs <= rhs); }
bool AIProject::Graph::operator >= (const NodeRecord &lhs, const NodeRecord &rhs) { return !(lhs < rhs); }

// These operators are slightly different as they compare the nodeID instead of g(x)

bool AIProject::Graph::operator == (const NodeRecord &lhs, const NodeRecord &rhs) { if (lhs.node == rhs.node) return true; return false; }
bool AIProject::Graph::operator != (const NodeRecord &lhs, const NodeRecord &rhs) { return !(lhs == rhs); }