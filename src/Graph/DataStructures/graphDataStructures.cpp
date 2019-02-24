#include "graphDataStructures.h"

AIProject::Graph::DirectedWeightedGraph::~DirectedWeightedGraph()
{
	v_edgeList.clear();
	v_edgeList.shrink_to_fit();

	v_positionList.clear();
	v_positionList.shrink_to_fit();

	v_nodeList.clear();
	v_nodeList.shrink_to_fit();
}

std::vector<AIProject::Graph::DirectedWeightedEdge> AIProject::Graph::DirectedWeightedGraph::GetOutGoingEdges(const int & i_node) const
{
	std::vector<DirectedWeightedEdge> list;

	for (size_t i = 0; i < v_edgeList.size(); i++)
	{
		if (v_edgeList[i].GetSource() == i_node)
			list.push_back(v_edgeList[i]);
	}

	return list;
}

int AIProject::Graph::DirectedWeightedGraph::AddNode(const ofVec2f &i_position)
{
	int nodeID = v_nodeList.size();

	v_nodeList.push_back(nodeID);
	v_positionList.push_back(i_position);

	return nodeID;
}

bool AIProject::Graph::DirectedWeightedGraph::AddEdge(const int & i_source, const int & i_sink, const int & i_cost)
{
	if (i_source > v_nodeList.size() || i_sink > v_nodeList.size() || i_sink == i_source)
		return false;

	v_edgeList.push_back(DirectedWeightedEdge(i_source, i_sink, i_cost));

	return true;
}

ofVec2f AIProject::Graph::DirectedWeightedGraph::Localize(const int & i_nodeID) const
{
	if (i_nodeID >= v_nodeList.size())
		return ofVec2f();

	return v_positionList[i_nodeID];
}

