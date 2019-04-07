#include "task.h"

#include "../Blackboard/blackboard.h"
#include "Tick/tick.h"
#include "status.h"

AIProject::DecisionMaking::Status AIProject::DecisionMaking::Task::Run(const Tick & i_Tick)
{
	Enter(i_Tick);

	void* boolean = i_Tick.m_blackboard.Get(Key::IsOpen, i_Tick.m_pTree->m_id, m_id);
	bool isOpen = *(static_cast<bool*>(boolean));


	return Status();
}

void AIProject::DecisionMaking::Task::Enter(const Tick & i_Tick)
{
}

void AIProject::DecisionMaking::Task::Open(const Tick & i_Tick)
{
}

void AIProject::DecisionMaking::Task::Execute(const Tick & i_Tick)
{
}

void AIProject::DecisionMaking::Task::Close(const Tick & i_Tick)
{
}

void AIProject::DecisionMaking::Task::Exit(const Tick & i_Tick)
{
}
