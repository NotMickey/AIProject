#include "task_ChasePlayer.h"

#include "../../../DecisionMaking/BehaviorTree/status.h"
#include "../../../DecisionMaking/BehaviorTree/Tick/tick.h"

#include "../Actions/action_Move.h"

AIProject::DecisionMaking::Task_ChasePlayer::Task_ChasePlayer(int i_id, const std::shared_ptr<Boid> & i_thisBoid, const Graph::TileMap &i_tileMap)
	: Task(i_id), m_pBoid(i_thisBoid), m_tileMap(i_tileMap) {}

AIProject::DecisionMaking::Status AIProject::DecisionMaking::Task_ChasePlayer::OnExecute(Tick & i_tick)
{
	// Check if this task was already running
	if (i_tick.m_pBlackboard->GetBool(Key::RunningTask, i_tick.m_pTree->m_id, m_id))
	{
		ofVec2f currPosition = m_pBoid->m_kinematic.position;

		int currNode = m_tileMap.GetNodeAtPosition(currPosition);

		// check if task was successful
		if (currNode == targetNode)
		{
			i_tick.m_pBlackboard->Set(Key::RunningTask, false, i_tick.m_pTree->m_id, m_id);
			return Status::SUCCESS;
		}
		
		// else keep running
		return Status::RUNNING;
	}

	//else create a new action, set it to blackboard and return running
	ofVec2f targetPosition = i_tick.m_pBlackboard->GetPlayer()->m_kinematic.position;

	targetNode = m_tileMap.GetNodeAtPosition(targetPosition);

	std::shared_ptr<Action> action = std::make_shared<Action_Move>(Action_Move(m_pBoid, targetNode, m_tileMap, 10.0f, 10, true));

	i_tick.m_pBlackboard->Set(Key::RunningTask, true, i_tick.m_pTree->m_id, m_id);
	i_tick.m_pBlackboard->Set(Key::action, action, i_tick.m_pTree->m_id);

	return Status::RUNNING;
}
