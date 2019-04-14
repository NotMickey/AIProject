#include "task_PlayerCheck.h"

#include "../../../DecisionMaking/BehaviorTree/Tick/tick.h"
#include "../../../DecisionMaking/BehaviorTree/status.h"

AIProject::DecisionMaking::Task_PlayerCheck::Task_PlayerCheck(int i_id, float i_minDist, const std::shared_ptr<Boid> & i_thisBoid)
	: Task(i_id), m_minDistance(i_minDist), m_pThisBoid(i_thisBoid) {}

AIProject::DecisionMaking::Status AIProject::DecisionMaking::Task_PlayerCheck::OnExecute(Tick & i_tick)
{
	// Check if player is in chase range
	if (m_pThisBoid->m_kinematic.position.squareDistance(i_tick.m_pBlackboard->GetPlayer()->m_kinematic.position) < (m_minDistance * m_minDistance))
		return Status::SUCCESS;

	// Check for global Alert status
	if (i_tick.m_pBlackboard->GetBool(Key::Alerted, 0, 0))
		return Status::SUCCESS;

	return Status::FAILURE;
}
