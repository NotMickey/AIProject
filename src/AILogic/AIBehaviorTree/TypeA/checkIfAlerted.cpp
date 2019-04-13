#include "checkIfAlerted.h"

#include "../../../DecisionMaking/Blackboard/blackboard.h"
#include "../../../DecisionMaking/BehaviorTree/Tick/tick.h"
#include "../../../DecisionMaking/BehaviorTree/status.h"

AIProject::DecisionMaking::CheckIfAlerted::CheckIfAlerted(int i_id) : Task(i_id) {}

AIProject::DecisionMaking::Status AIProject::DecisionMaking::CheckIfAlerted::OnExecute(Tick & i_tick)
{
	// Check for global Alert status
	if (i_tick.m_pBlackboard->GetBool(Key::Alerted, 0, 0))
		return Status::SUCCESS;

	// Check for local alert status
	if (i_tick.m_pBlackboard->GetBool(Key::Alerted, i_tick.m_pTree->m_id, 0))
		return Status::SUCCESS;

	return Status::FAILURE;
}
