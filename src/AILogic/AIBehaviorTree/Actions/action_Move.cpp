#include "action_Move.h"

#include "../../../Graph/Algorithm/AStar/AStar.h"
#include "../../../Graph/Algorithm/AStar/AStarHelper.h"

#include "../../../Graph/Algorithm/AStar/Heuristic/eulerHeuristic.h"

AIProject::DecisionMaking::Action_Move::Action_Move(const std::shared_ptr<Boid>& i_character, int i_targetNode, const Graph::TileMap & i_tileMap,
											float i_expiryTime, int i_priority, bool i_canInterrupt)
	: Action(i_expiryTime, i_priority, i_canInterrupt), m_pCharacter(i_character), m_targetNode(i_targetNode), m_tileMap(i_tileMap)
{
	id = 4;
}

void AIProject::DecisionMaking::Action_Move::Execute()
{
	int sourceNode = m_tileMap.GetNodeAtPosition(m_pCharacter->m_kinematic.position);

	if (sourceNode == m_targetNode || m_targetNode == -1)
	{
		isComplete = true;
		return;
	}

	AIProject::Graph::Heuristic* complexHeuristic = new AIProject::Graph::EulerHeuristic(m_targetNode, m_tileMap.GetGraph());

	std::vector<AIProject::Graph::DirectedWeightedEdge> path = AIProject::Graph::FindPath(sourceNode, m_targetNode, m_tileMap.GetGraph(), complexHeuristic);

	std::vector<ofVec2f> waypoints;

	for (int i = path.size() - 1; i >= 0; --i)
	{
		ofVec2f point = m_tileMap.GetGraph().Localize(path[i].GetSink());
		waypoints.push_back(point);
	}

	ofVec2f point = m_tileMap.GetGraph().Localize(sourceNode);
	waypoints.push_back(point);

	m_pCharacter->SetWayPoints(waypoints);

	isComplete = true;

	delete complexHeuristic;
}


