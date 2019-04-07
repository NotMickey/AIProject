#include "tick.h"

AIProject::DecisionMaking::Tick::Tick(const BehaviorTree* i_behaviorTree, Blackboard &i_blackBoard)
								: m_pTree(i_behaviorTree), m_blackboard(i_blackBoard)
{}

AIProject::DecisionMaking::Tick::~Tick()
{
	m_pTree = nullptr;
}
