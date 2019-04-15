#include "task_PlayerCheck.h"

#include "../../../DecisionMaking/BehaviorTree/Tick/tick.h"
#include "../../../DecisionMaking/BehaviorTree/status.h"

AIProject::DecisionMaking::Task_PlayerCheck::Task_PlayerCheck(int i_id, const std::shared_ptr<Boid> & i_thisBoid)
	: Task(i_id), m_pBoid(i_thisBoid) {}

AIProject::DecisionMaking::Status AIProject::DecisionMaking::Task_PlayerCheck::OnExecute(Tick & i_tick)
{
	// Check if player is in chase range

	float aggroDistance = i_tick.m_pBlackboard->GetInt(Key::AggroDistance, i_tick.m_pTree->m_treeId, 0);

	if (m_pBoid->m_kinematic.position.squareDistance(i_tick.m_pBlackboard->GetPlayer()->m_kinematic.position) < (aggroDistance * aggroDistance))
	{
		i_tick.m_pBlackboard->Set(Key::Alerted, true, i_tick.m_pTree->m_treeId, 0); 

		return Status::SUCCESS;
	}

	i_tick.m_pBlackboard->Set(Key::Alerted, false, i_tick.m_pTree->m_treeId, 0);

	return Status::FAILURE;
}
