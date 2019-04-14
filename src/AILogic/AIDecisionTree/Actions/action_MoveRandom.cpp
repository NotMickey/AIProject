#include "action_MoveRandom.h"

#include <random>

#include "../../../Graph/Algorithm/AStar/AStar.h"
#include "../../../Graph/Algorithm/AStar/AStarHelper.h"

#include "../../../Graph/Algorithm/AStar/Heuristic/eulerHeuristic.h"

AIProject::DecisionMaking::Action_MoveRandom::Action_MoveRandom(const std::shared_ptr<Boid>& i_character, const Graph::TileMap & i_tileMap,
											float i_expiryTime, int i_priority, bool i_canInterrupt)
	: Action(i_expiryTime, i_priority, i_canInterrupt), m_pCharacter(i_character), m_tileMap(i_tileMap)
{
	id = 1;
	queuedTime = 0.0f;
}

void AIProject::DecisionMaking::Action_MoveRandom::Execute()
{
	int startNode = m_tileMap.GetNodeAtPosition(m_pCharacter->m_kinematic.position);

	float x = (rand() % (int)(m_pCharacter->m_kinematic.position.x + 120 - (m_pCharacter->m_kinematic.position.x - 120))) + (m_pCharacter->m_kinematic.position.x - 120); // Random X pos
	float y = (rand() % (int)(m_pCharacter->m_kinematic.position.y + 120 - (m_pCharacter->m_kinematic.position.y - 120))) + (m_pCharacter->m_kinematic.position.y - 120); // Random Y pos

	int goalNode = m_tileMap.GetNodeAtPosition(ofVec2f(x, y));

	if (goalNode == -1)
		goalNode = 1;

	AIProject::Graph::Heuristic* complexHeuristic = new AIProject::Graph::EulerHeuristic(goalNode, m_tileMap.GetGraph());

	std::vector<AIProject::Graph::DirectedWeightedEdge> path = AIProject::Graph::FindPath(startNode, goalNode, m_tileMap.GetGraph(), complexHeuristic);

	std::vector<ofVec2f> waypoints;

	for (int i = path.size() - 1; i >= 0; --i)
	{
		ofVec2f point = m_tileMap.GetGraph().Localize(path[i].GetSink());
		waypoints.push_back(point);
	}

	ofVec2f point = m_tileMap.GetGraph().Localize(startNode);
	waypoints.push_back(point);

	m_pCharacter->SetWayPoints(waypoints);

	isComplete = true;

	delete complexHeuristic;
}
