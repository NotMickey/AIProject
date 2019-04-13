#pragma once

#include "../../DecisionMaking/TreeBase/decisionMakingBehavior.h"
#include "../../DecisionMaking/ActionManager/actionManager.h"

namespace AIProject
{
	class AIBrain
	{
	public:
		AIBrain(DecisionMaking::DecisionMakingBehavior* i_tree);

		void Update(float i_deltaTime);

		~AIBrain();

	private:
		std::shared_ptr<DecisionMaking::DecisionMakingBehavior> m_tree;

		DecisionMaking::ActionManager m_actionManager;
	};
}