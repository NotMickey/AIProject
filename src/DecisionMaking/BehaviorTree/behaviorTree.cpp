#include "behaviorTree.h"

#include "Tick/tick.h"

AIProject::DecisionMaking::BehaviorTree::BehaviorTree(int i_id, const std::shared_ptr<Blackboard>& i_blackboard)
	: m_id(i_id), m_pBlackboard(i_blackboard), m_pRoot(nullptr) {}

std::shared_ptr<AIProject::DecisionMaking::Action> AIProject::DecisionMaking::BehaviorTree::GetAction()
{
	if (m_pRoot != nullptr)
	{
		Tick tick(this, m_pBlackboard);

		m_pRoot->Run(tick);

		return m_pBlackboard->GetAction(Key::action, m_pRoot->m_id);
	}

	return std::shared_ptr<Action>();
}

AIProject::DecisionMaking::BehaviorTree::~BehaviorTree()
{
	if (m_pRoot != nullptr)
	{
		delete m_pRoot;
		m_pRoot = nullptr;
	}
}
