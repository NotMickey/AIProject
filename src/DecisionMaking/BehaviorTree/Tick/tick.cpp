#include "tick.h"

AIProject::DecisionMaking::Tick::Tick(const BehaviorTree* i_behaviorTree, const std::shared_ptr<Blackboard> &i_blackBoard)
								: m_pTree(i_behaviorTree), m_pBlackboard(i_blackBoard) {}

void AIProject::DecisionMaking::Tick::OpenTask(Task* const i_task)
{
	m_vOpenTasks.push_back(i_task);
}

void AIProject::DecisionMaking::Tick::CloseTask(Task* const i_task)
{
	auto it = m_vOpenTasks.begin();

	while (it != m_vOpenTasks.end())
	{
		if (*it == i_task)
			it = m_vOpenTasks.erase(it);
		else
			++it;
	}
}

void AIProject::DecisionMaking::Tick::EnterTask(Task* const i_task) const
{
	// Log something!
}

void AIProject::DecisionMaking::Tick::ExecuteTask(Task* const i_task) const
{
	// Log something!
}

void AIProject::DecisionMaking::Tick::ExitTask(Task* const i_task) const
{
	// Log something!
}

AIProject::DecisionMaking::Tick::~Tick()
{
	m_pTree = nullptr;
}
