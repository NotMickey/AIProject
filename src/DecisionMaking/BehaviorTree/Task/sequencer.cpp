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
	int runningChild = i_tick.m_blackboard.GetInt(Key::RunningChild, i_tick.m_pTree->m_id, m_id);

	if (runningChild < 0)
		return Status::SUCCESS;

	for (int i = runningChild; i < GetChildren().size(); i++)
	{
		Status childStat = (GetChildren()[i])->Run(i_tick);

		if (childStat != Status::SUCCESS)
		{
			if (childStat == Status::RUNNING)
			{
				i_tick.m_blackboard.Set(Key::RunningChild, i, i_tick.m_pTree->m_id, m_id);

				return childStat;
			}

			// Getting here means the child either FAILED or retured ERROR so don't run others
			break;
		}
	}

	return Status::SUCCESS;
}