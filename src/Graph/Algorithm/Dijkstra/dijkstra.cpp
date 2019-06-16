#include "dijkstra.h"
#include "dijkstraHelper.h"

#include "../../DataStructures/Heap/heap.h"

std::vector<AIProject::Graph::DirectedWeightedEdge> AIProject::Graph::FindPath(const int & i_start, const int & i_goal, const DirectedWeightedGraph & i_graph)
{
	DirectedWeightedEdge edge;
	NodeRecordDijkstra startRecord(i_start, 0, edge);

	Heap<NodeRecordDijkstra> openList; // A priority queue
	openList.Add(startRecord);

	CloseListDijkstra closeList; // A vector list
	NodeRecordDijkstra currentRecord;

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

			NodeRecordDijkstra endNodeRecord;
			endNodeRecord.node = endNode;

			if (closeList.Contains(endNode))
			{
				continue;
			}
			else if (openList.Contains(endNodeRecord))
			{
				endNodeRecord = openList.Find(endNodeRecord);

				if (endNodeRecord.costSoFar <= g)
					continue;

				// Need to remove this node record from the open list?
			}

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

	std::cout << "Dijkstra nodes visited = " << nodesVisited << "\n";

	using std::reverse;

	std::reverse(goalPath.begin(), goalPath.end());

	return goalPath;
}
