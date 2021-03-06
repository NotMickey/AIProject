#include "aiBrain.h"

AIProject::AIBrain::AIBrain(DecisionMaking::DecisionMakingBehavior * i_tree) : m_tree(i_tree) {}

void AIProject::AIBrain::Update(float i_deltaTime)
{
	std::shared_ptr<DecisionMaking::Action> action;

	if (m_tree != nullptr)
		action = m_tree->GetAction();

	if (action != nullptr)
	{
		m_actionManager.ScheduleAction(action);
	}

	m_actionManager.Update(i_deltaTime);
}

AIProject::AIBrain::~AIBrain()
{
	// NEEDS TO BE UPDATED
}
