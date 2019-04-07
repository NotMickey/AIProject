#include "behaviorTree.h"

#include "Tick/tick.h"

AIProject::DecisionMaking::Status AIProject::DecisionMaking::BehaviorTree::GetAction()
{
	Tick tick(this, m_blackboard);

	m_root.Run(tick);

	// currentOpenTasks = tick.opentasks;
	// return m_blackboard.get("action");

	return Status();
}
