#include "sequencer.h"

#include "../../Blackboard/blackboard.h"
#include "../Tick/tick.h"
#include "../status.h"

void AIProject::DecisionMaking::Sequencer::OnOpen(const Tick & i_tick)
{
	i_tick.m_blackboard.Set(Key::RunningChild, 0, i_tick.m_pTree->m_id, m_id);
}

AIProject::DecisionMaking::Status AIProject::DecisionMaking::Sequencer::OnExecute(Tick & i_tick)
{
	int runningChild = *static_cast<int*>(i_tick.m_blackboard.Get(Key::RunningChild, i_tick.m_pTree->m_id, m_id));

	for (int i = runningChild; i < GetChildren().size(); i++)
	{
		std::shared_ptr<Task> childTask = (GetChildren()[i]);

		Status childStat = childTask->Run(i_tick);

		if (childStat != Status::SUCCESS)
		{
			if (childStat == Status::RUNNING)
			{
				i_tick.m_blackboard.Set(Key::RunningChild, i, i_tick.m_pTree->m_id, m_id);

				return childStat;
			}
		}
	}

	return Status::SUCCESS;
}