#include "randomDecorator.h"

#include "../../Blackboard/blackboard.h"
#include "../Tick/tick.h"
#include "../status.h"

void AIProject::DecisionMaking::RandomDecorator::OnOpen(const Tick & i_tick)
{
	i_tick.m_pBlackboard->Set(Key::RunningChild, -1, i_tick.m_pTree->m_treeId, m_id);
}

AIProject::DecisionMaking::Status AIProject::DecisionMaking::RandomDecorator::OnExecute(Tick & i_tick)
{
	int children = GetChildren().size();

	if (children == 0)
		return Status::SUCCESS;

	int child = rand() % children;

	int runningChild = i_tick.m_pBlackboard->GetInt(Key::RunningChild, i_tick.m_pTree->m_treeId, m_id);

	if (runningChild >= 0)
		child = runningChild;

	Status childStat = (GetChildren()[child])->Run(i_tick);

	if (childStat == Status::RUNNING)
	{
		i_tick.m_pBlackboard->Set(Key::RunningChild, child, i_tick.m_pTree->m_treeId, m_id);

		return childStat;
	}

	i_tick.m_pBlackboard->Set(Key::RunningChild, -1, i_tick.m_pTree->m_treeId, m_id);

	return childStat;
}
