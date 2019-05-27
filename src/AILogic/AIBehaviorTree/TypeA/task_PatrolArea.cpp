#include "task_PatrolArea.h"

#include "../../../DecisionMaking/BehaviorTree/Tick/tick.h"
#include "../../../DecisionMaking/BehaviorTree/status.h"

#include "../Actions/action_Move.h"

AIProject::DecisionMaking::Task_PatrolArea::Task_PatrolArea(int i_id, const std::shared_ptr<Boid>& i_thisBoid, const Graph::TileMap & i_tileMap, const std::vector<int>& i_nodes)
	: Task(i_id), m_pBoid(i_thisBoid), m_tileMap(i_tileMap), m_vPatrolNodes(i_nodes), m_iterator(0) {}

AIProject::DecisionMaking::Status AIProject::DecisionMaking::Task_PatrolArea::OnExecute(Tick & i_tick)
{
	// Check if player was detected while patrolling
	float aggroDistance = i_tick.m_pBlackboard->GetInt(Key::AggroDistance, i_tick.m_pTree->m_treeId, 0);

	if (m_pBoid->m_kinematic.position.squareDistance(i_tick.m_pBlackboard->GetPlayer()->m_kinematic.position) < (aggroDistance * aggroDistance))
	{
		i_tick.m_pBlackboard->Set(Key::Alerted, true, i_tick.m_pTree->m_treeId, 0);
		i_tick.m_pBlackboard->Set(Key::RunningTask, false, i_tick.m_pTree->m_treeId, m_id);

		return Status::FAILURE;
	}

	if (m_vPatrolNodes.empty())
		return Status::FAILURE;

	// Get current target node
	int targetNode = i_tick.m_pBlackboard->GetInt(Key::CurrentPatrolNode, i_tick.m_pTree->m_treeId, 0);

	if (targetNode == -1)
		targetNode = m_vPatrolNodes[m_iterator];

	// Check if this task was already running
	if (i_tick.m_pBlackboard->GetBool(Key::RunningTask, i_tick.m_pTree->m_treeId, m_id))
	{
		ofVec2f currPosition = m_pBoid->m_kinematic.position;

		int currNode = m_tileMap.GetNodeAtPosition(currPosition);

		// check if task was successful
		if (currNode == targetNode)
		{
			i_tick.m_pBlackboard->Set(Key::RunningTask, false, i_tick.m_pTree->m_treeId, m_id);
			return Status::SUCCESS;
		}

		// Check for edge cases
		if (currNode == -1)
		{
			i_tick.m_pBlackboard->Set(Key::RunningTask, false, i_tick.m_pTree->m_treeId, m_id);
			return Status::FAILURE;
		}

		// else keep running
		return Status::RUNNING;
	}

	// Set new target node and create its corresponding action
	targetNode = m_vPatrolNodes[m_iterator++];

	if (m_iterator >= m_vPatrolNodes.size())
		m_iterator = 0;

	std::shared_ptr<Action> action = std::make_shared<Action_Move>(Action_Move(m_pBoid, targetNode, m_tileMap, 10.0f, 5, true));

	i_tick.m_pBlackboard->Set(Key::RunningTask, true, i_tick.m_pTree->m_treeId, m_id);
	i_tick.m_pBlackboard->Set(Key::CurrentPatrolNode, targetNode, i_tick.m_pTree->m_treeId, 0);
	i_tick.m_pBlackboard->Set(Key::action, action, i_tick.m_pTree->m_treeId);

	return Status::RUNNING;
}
