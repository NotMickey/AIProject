#include "tick.h"

AIProject::DecisionMaking::Tick::Tick(const BehaviorTree* i_behaviorTree, Blackboard &i_blackBoard)
								: m_pTree(i_behaviorTree), m_blackboard(i_blackBoard)
{}

void AIProject::DecisionMaking::Tick::OpenTask(const Task &i_task)
{
	m_vOpenTasks.push_back(i_task);
}

void AIProject::DecisionMaking::Tick::CloseTask(const Task &i_task)
{
	auto it = m_vOpenTasks.begin();

	while (it != m_vOpenTasks.end())
	{
		if (*it == i_task)
			m_vOpenTasks.erase(it);
		else
			++it;
	}
}

void AIProject::DecisionMaking::Tick::EnterTask(const Task & i_task) const
{
	// Log something!
}

void AIProject::DecisionMaking::Tick::ExecuteTask(const Task & i_task) const
{
	// Log something!
}

void AIProject::DecisionMaking::Tick::ExitTask(const Task & i_task) const
{
	// Log something!
}

AIProject::DecisionMaking::Tick::~Tick()
{
	m_pTree = nullptr;
}
