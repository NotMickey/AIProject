#include "selector.h"

#include "../../Blackboard/blackboard.h"
#include "../Tick/tick.h"
#include "../status.h"

void AIProject::DecisionMaking::Selector::OnOpen(const Tick & i_tick)
{
	i_tick.m_blackboard.Set(Key::RunningChild, 0, i_tick.m_pTree->m_id, m_id);
}

AIProject::DecisionMaking::Status AIProject::DecisionMaking::Selector::OnExecute(Tick & i_tick)
{
	int runningChild = i_tick.m_blackboard.GetInt(Key::RunningChild, i_tick.m_pTree->m_id, m_id);

	for (int i = runningChild; i < GetChildren().size(); i++)
	{
		Status childStat = (GetChildren()[i])->Run(i_tick);

		if (childStat != Status::FAILURE)
		{
			if (childStat == Status::RUNNING)
			{
				i_tick.m_blackboard.Set(Key::RunningChild, i, i_tick.m_pTree->m_id, m_id);

				return childStat;
			}

			// Getting here means a child returned SUCCESS so don't run others
			break;
		}
	}

	return Status::FAILURE;
}
