#include "task.h"

#include "../Blackboard/blackboard.h"
#include "Tick/tick.h"
#include "status.h"

AIProject::DecisionMaking::Status AIProject::DecisionMaking::Task::Run(const Tick & i_tick)
{
	Enter(i_tick);

	void* boolean = i_tick.m_blackboard.Get(Key::IsOpen, i_tick.m_pTree->m_id, m_id);
	bool isOpen = *(static_cast<bool*>(boolean));

	if (!isOpen)
		Open(i_tick);

	Status stat = Execute(i_tick);

	if (stat != Status::RUNNING)
		Close(i_tick);

	Exit(i_tick);

	return stat;
}

void AIProject::DecisionMaking::Task::Enter(const Tick & i_tick)
{
	OnEnter(i_tick);
	//i_tick.EnterTask(this);
}

void AIProject::DecisionMaking::Task::Open(const Tick & i_tick)
{
	OnOpen(i_tick);
	//i_tick.OpenTask(this);
	i_tick.m_blackboard.Set(Key::IsOpen, true, i_tick.m_pTree->m_id, m_id);
}

AIProject::DecisionMaking::Status AIProject::DecisionMaking::Task::Execute(const Tick & i_tick)
{
	Status stat = OnExecute(i_tick);
	//i_tick.ExecuteTask(this);

	return stat;
}

void AIProject::DecisionMaking::Task::Close(const Tick & i_tick)
{
	OnClose(i_tick);
	//i_tick.CloseTask(this);
	i_tick.m_blackboard.Set(Key::IsOpen, false, i_tick.m_pTree->m_id, m_id);
}

void AIProject::DecisionMaking::Task::Exit(const Tick & i_tick)
{
	OnExit(i_tick);
	//i_tick.ExitTask(this);
}
