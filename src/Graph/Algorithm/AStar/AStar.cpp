#include "AStar.h"
#include "AStarHelper.h"

#include "../../DataStructures/Heap/heap.h"
#include "Heuristic/heuristic.h"

std::vector<AIProject::Graph::DirectedWeightedEdge> AIProject::Graph::FindPath(const int & i_start, const int & i_goal, const DirectedWeightedGraph & i_graph,
																				const Heuristic * const i_heuristic)
{
	DirectedWeightedEdge edge;
	NodeRecord startRecord(i_start, 0, i_heuristic->Estimate(i_start), edge);

	Heap<NodeRecord> openList; // A priority queue
	openList.Add(startRecord);

	CloseList closeList; // A vector list
	NodeRecord currentRecord;

	int nodesVisited = 0;

	while (openList.GetSize() != 0)
	{
		currentRecord = openList.Remove();

		nodesVisited++;

		if (currentRecord.node == i_goal) break;

		std::vector<DirectedWeightedEdge> outgoingEdges = i_graph.GetOutGoingEdges(currentRecord.node);

		if (outgoingEdges.size() == 0) continue;

		for each (DirectedWeightedEdge edge in outgoingEdges)
		{
			int endNode = edge.GetSink();

			int g = currentRecord.costSoFar + edge.GetCost();
			int h = -1;

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
			// Should this be another if statement??
			else if (openList.Contains(endNodeRecord))
			{
				endNodeRecord = openList.Find(endNodeRecord);

				if (endNodeRecord.costSoFar <= g)
					continue;

				// Need to remove it from the open list? Or better yet update it on the openlist (re-evaluate priority)

				h = endNodeRecord.estimatedTotalCost - endNodeRecord.costSoFar;
			}
			else
			{
				h = i_heuristic->Estimate(endNode);

				endNodeRecord.estimatedTotalCost = g + h;
				endNodeRecord.costSoFar = g;
				endNodeRecord.incomingEdge = edge;
			}

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

	std::cout << "A* nodes visited = " << nodesVisited << "\n";

	using std::reverse;

	std::reverse(goalPath.begin(), goalPath.end());

	return goalPath;
}

