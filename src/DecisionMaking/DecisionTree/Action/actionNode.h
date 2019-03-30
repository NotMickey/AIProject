#pragma once

#include <memory>

#include "../decisionNodeBase.h"
#include "../../ActionManager/action.h"

namespace AIProject
{
	namespace DecisionMaking
	{
		class ActionNode : public DecisionNodeBase 
		{
		public:
			ActionNode(const Action &i_Action) : m_pAction(std::make_shared<Action*>(i_Action)) {}

			inline virtual DecisionNodeBase* MakeDecision() override { return this; }

			inline std::shared_ptr<Action*> GetAction() { return m_pAction; }

		private:
			std::shared_ptr<Action*> m_pAction;
		};
	}
}