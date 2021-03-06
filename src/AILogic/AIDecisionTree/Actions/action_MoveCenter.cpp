#include "action_MoveCenter.h"

#include "../../../Graph/Algorithm/AStar/AStar.h"
#include "../../../Graph/Algorithm/AStar/AStarHelper.h"

AIProject::DecisionMaking::Action_MoveCenter::Action_MoveCenter(const std::shared_ptr<Boid>& i_character, const Graph::TileMap &i_tileMap,
														float i_expiryTime, int i_priority, bool i_canInterrupt)
	: Action(i_expiryTime, i_priority, i_canInterrupt), m_pCharacter(i_character), m_tileMap(i_tileMap), m_bIsMoving(false)
{
	id = 2;

	float x = ofGetWidth() / 2;
	float y = ofGetHeight() / 2;

	m_centerNode = m_tileMap.GetNodeAtPosition(ofVec2f(x, y));

	if (m_centerNode == -1)
		m_centerNode = 1;
}

void AIProject::DecisionMaking::Action_MoveCenter::Execute()
{
	int startNode = m_tileMap.GetNodeAtPosition(m_pCharacter->m_kinematic.position);

	if (startNode == -1)
		startNode = 1;

	if (m_centerNode == startNode)
	{
		m_bIsMoving = false;
		isComplete = true;
		return;
	}

	if (m_bIsMoving)
		return;

	AIProject::Graph::Heuristic* complexHeuristic = new AIProject::Graph::EulerHeuristic(m_centerNode, m_tileMap.GetGraph());

	std::vector<AIProject::Graph::DirectedWeightedEdge> path = AIProject::Graph::FindPath(startNode, m_centerNode, m_tileMap.GetGraph(), complexHeuristic);

	std::vector<ofVec2f> waypoints;

	for (int i = path.size() - 1; i >= 0; --i)
	{
		ofVec2f point = m_tileMap.GetGraph().Localize(path[i].GetSink());
		waypoints.push_back(point);
	}

	ofVec2f point = m_tileMap.GetGraph().Localize(startNode);
	waypoints.push_back(point);

	m_pCharacter->SetWayPoints(waypoints);

	m_bIsMoving = true;

	delete complexHeuristic;
}
