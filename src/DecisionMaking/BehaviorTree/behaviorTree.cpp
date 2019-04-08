#include "behaviorTree.h"

#include "Tick/tick.h"

std::shared_ptr<AIProject::DecisionMaking::Action> AIProject::DecisionMaking::BehaviorTree::GetAction()
{
	Tick tick(this, m_blackboard);

	Status stat = m_pRoot->Run(tick);
	 
	// currentOpenTasks = tick.opentasks;
	// return m_blackboard.get("action");
}
