#include "dijkstraHelper.h"

bool AIProject::Graph::CloseListDijkstra::Contains(const int & nodeID)
{
	for (size_t i = 0; i < list.size(); i++)
	{
		if (list[i].node == nodeID)
			return true;
	}

	return false;
}

AIProject::Graph::NodeRecordDijkstra AIProject::Graph::CloseListDijkstra::Find(const int & nodeID)
{
	for (size_t i = 0; i < list.size(); i++)
	{
		if (list[i].node == nodeID)
			return list[i];
	}

	return NodeRecordDijkstra();
}

void AIProject::Graph::CloseListDijkstra::Remove(const int & nodeID)
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

bool AIProject::Graph::operator < (const NodeRecordDijkstra &lhs, const NodeRecordDijkstra &rhs) { if (lhs.costSoFar < rhs.costSoFar) return true; return false; }
bool AIProject::Graph::operator <= (const NodeRecordDijkstra &lhs, const NodeRecordDijkstra &rhs) { if (lhs.costSoFar <= rhs.costSoFar) return true; return false; }

bool AIProject::Graph::operator > (const NodeRecordDijkstra &lhs, const NodeRecordDijkstra &rhs) { return !(lhs <= rhs); }
bool AIProject::Graph::operator >= (const NodeRecordDijkstra &lhs, const NodeRecordDijkstra &rhs) { return !(lhs < rhs); }

// These operators are slightly different as they compare the nodeID instead of g(x)

bool AIProject::Graph::operator == (const NodeRecordDijkstra &lhs, const NodeRecordDijkstra &rhs) { if (lhs.node == rhs.node) return true; return false; }
bool AIProject::Graph::operator != (const NodeRecordDijkstra &lhs, const NodeRecordDijkstra &rhs) { return !(lhs == rhs); }