#include "behaviorTree.h"

#include "Tick/tick.h"

AIProject::DecisionMaking::BehaviorTree::BehaviorTree(int i_treeId, const std::shared_ptr<Blackboard>& i_blackboard)
	: m_treeId(i_treeId), m_pBlackboard(i_blackboard), m_pRoot(nullptr) {}

std::shared_ptr<AIProject::DecisionMaking::Action> AIProject::DecisionMaking::BehaviorTree::GetAction()
{
	std::shared_ptr<Action> activeAction;

	if (m_pRoot != nullptr)
	{
		Tick tick(this, m_pBlackboard);

		m_pRoot->Run(tick);

		activeAction = m_pBlackboard->GetAction(Key::action, m_treeId);
		
		if (activeAction != nullptr)
		{
			m_pBlackboard->ClearAction(m_treeId);

			return activeAction;
		}
	}

	return activeAction;
}

AIProject::DecisionMaking::BehaviorTree::~BehaviorTree()
{
	if (m_pRoot != nullptr)
	{
		delete m_pRoot;
		m_pRoot = nullptr;
	}
}
