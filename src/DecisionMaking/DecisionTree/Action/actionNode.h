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
			ActionNode(const std::shared_ptr<Action> &i_action) : m_pAction(i_action) {}

			inline virtual DecisionNodeBase* MakeDecision() override { return this; }

			inline std::shared_ptr<Action> GetAction() { return m_pAction; }

			virtual ~ActionNode() {}

		private:
			std::shared_ptr<Action> m_pAction;
		};
	}
}