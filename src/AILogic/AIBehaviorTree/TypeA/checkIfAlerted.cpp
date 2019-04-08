#include "checkIfAlerted.h"

#include "../../../DecisionMaking/Blackboard/blackboard.h"
#include "../../../DecisionMaking/BehaviorTree/Tick/tick.h"
#include "../../../DecisionMaking/BehaviorTree/status.h"

AIProject::DecisionMaking::CheckIfAlerted::CheckIfAlerted(const int & i_id)
	: Task(i_id)
{}

AIProject::DecisionMaking::Status AIProject::DecisionMaking::CheckIfAlerted::OnExecute(Tick & i_tick)
{
	if (i_tick.m_blackboard.GetBool(Key::Alerted, 0, 0))
		return Status::SUCCESS;

	return Status::FAILURE;
}
