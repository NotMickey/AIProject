#include "graphDataStructures.h"

AIProject::Graph::DirectedWeightedGraph::~DirectedWeightedGraph()
{
	v_edgeList.clear();
	v_edgeList.shrink_to_fit();

	v_nodeList.clear();
	v_nodeList.shrink_to_fit();
}

std::vector<AIProject::Graph::DirectedWeightedEdge> AIProject::Graph::DirectedWeightedGraph::GetOutGoingEdges(const int & node) const
{
	std::vector<DirectedWeightedEdge> list;

	for (int i = 0; i < v_edgeList.size(); i++)
	{
		if (v_edgeList[i].GetSource() == node)
			list.push_back(v_edgeList[i]);
	}

	return list;
}

int AIProject::Graph::DirectedWeightedGraph::AddNode()
{
	int nodeID = v_nodeList.size();

	v_nodeList.push_back(nodeID);

	return nodeID;
}

bool AIProject::Graph::DirectedWeightedGraph::AddEdge(const int & i_source, const int & i_sink, const int & i_cost)
{
	if (i_source > v_nodeList.size() || i_sink > v_nodeList.size() || i_sink == i_source)
		return false;

	v_edgeList.push_back(DirectedWeightedEdge(i_source, i_sink, i_cost));

	return true;
}

bool AIProject::Graph::operator < (const NodeRecord &lhs, const NodeRecord &rhs) { if (lhs.costSoFar < rhs.costSoFar) return true; return false; }
bool AIProject::Graph::operator <= (const NodeRecord &lhs, const NodeRecord &rhs) { if (lhs.costSoFar <= rhs.costSoFar) return true; return false; }

bool AIProject::Graph::operator > (const NodeRecord &lhs, const NodeRecord &rhs) { return !(lhs <= rhs); }
bool AIProject::Graph::operator >= (const NodeRecord &lhs, const NodeRecord &rhs) { return !(lhs < rhs); }

// These operators are slightly different as they compare the nodeID instead of g(x)

bool AIProject::Graph::operator == (const NodeRecord &lhs, const NodeRecord &rhs) { if (lhs.node == rhs.node) return true; return false; }
bool AIProject::Graph::operator != (const NodeRecord &lhs, const NodeRecord &rhs) { return !(lhs == rhs); }
