#pragma once

#include "TreeBase/decisionMakingBehavior.h"

#include "Task/TaskBase/task.h"
#include "../Blackboard/blackboard.h"

namespace AIProject
{
	namespace DecisionMaking
	{
		class BehaviorTree : public DecisionMakingBehavior
		{
		public:
			virtual std::shared_ptr<Action> GetAction() override;

			int m_id;

		protected:

			std::unique_ptr<Task> m_pRoot;
			Blackboard &m_blackboard;
		};
	}
}