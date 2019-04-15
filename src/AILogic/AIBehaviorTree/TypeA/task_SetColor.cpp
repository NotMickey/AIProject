#include "task_SetColor.h"

#include "../../../DecisionMaking/BehaviorTree/status.h"
#include "../../../DecisionMaking/BehaviorTree/Tick/tick.h"

AIProject::DecisionMaking::Task_SetColor::Task_SetColor(int i_id, const std::shared_ptr<Boid>& i_thisBoid, bool i_isAlerted)
	: Task(i_id), m_pBoid(i_thisBoid), m_bIsAlerted(i_isAlerted) {}

AIProject::DecisionMaking::Status AIProject::DecisionMaking::Task_SetColor::OnExecute(Tick & i_tick)
{
	// Check for global Alert status
	if (i_tick.m_pBlackboard->GetBool(Key::Alerted, 0, 0))
	{
		m_pBoid->ChangeBoidColor(ofColor(255, 0, 0, 255));
	}
	else
	{
		m_pBoid->ChangeBoidColor(ofColor(255, 255, 0, 255));
	}

	return Status::SUCCESS;
}
