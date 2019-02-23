#include "AStar.h"

#include "../DataStructures/heap.h"

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

std::vector<AIProject::Graph::DirectedWeightedEdge> AIProject::Graph::FindPath(const int & i_start, const int & i_goal, const DirectedWeightedGraph & i_graph,
																					const Heuristic & i_heuristic)
{
	DirectedWeightedEdge edge;
	NodeRecord startRecord(i_start, 0, i_heuristic.Estimate(i_start), edge);

	Heap<NodeRecord> openList; // A priority queue
	openList.Add(startRecord);

	CloseList closeList; // A vector list
	NodeRecord currentRecord;

	while (openList.GetSize() != 0)
	{
		currentRecord = openList.Remove();

		if (currentRecord.node == i_goal) break;

		std::vector<DirectedWeightedEdge> outgoingEdges = i_graph.GetOutGoingEdges(currentRecord.node);

		if (outgoingEdges.size() == 0) continue;

		for each (DirectedWeightedEdge edge in outgoingEdges)
		{
			int endNode = edge.GetSink();

			int g = currentRecord.costSoFar + edge.GetCost();
			int h;

			NodeRecord endNodeRecord;
			endNodeRecord.node = endNode;

			if (closeList.Contains(endNode))
			{
				endNodeRecord = closeList.Find(endNode);

				if (endNodeRecord.costSoFar <= g)
					continue;

				closeList.Remove(endNode);

				h = endNodeRecord.estimatedTotalCost - endNodeRecord.costSoFar;
			}
			else if (openList.Contains(endNodeRecord))
			{
				endNodeRecord = openList.Find(endNodeRecord);

				if (endNodeRecord.costSoFar <= g)
					continue;

				h = endNodeRecord.estimatedTotalCost - endNodeRecord.costSoFar;
			}
			else
			{
				h = i_heuristic.Estimate(endNode);
			}
				
			endNodeRecord.estimatedTotalCost = g + h;
			endNodeRecord.costSoFar = g;
			endNodeRecord.incomingEdge = edge;

			//if (!openList.Contains(endNodeRecord)) ??
			openList.Add(endNodeRecord);
		}

		closeList.list.push_back(currentRecord);
	}

	std::vector<DirectedWeightedEdge> goalPath;

	if (currentRecord.node != i_goal) return goalPath; // empty list!

	while (currentRecord.node != i_start)
	{
		goalPath.push_back(currentRecord.incomingEdge);

		currentRecord = closeList.Find(currentRecord.incomingEdge.GetSource());
	}

	using std::reverse;

	std::reverse(goalPath.begin(), goalPath.end());

	return goalPath;
}
