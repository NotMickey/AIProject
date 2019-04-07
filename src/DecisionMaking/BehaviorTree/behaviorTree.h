#pragma once

#include "TreeBase/decisionMakingBehavior.h"

#include "Task/TaskBase/task.h"
#include "../Blackboard/blackboard.h"

namespace AIProject
{
	namespace DecisionMaking
	{
		class BehaviorTree : DecisionMakingBehavior
		{
		public:
			virtual Status GetAction() override;

			int m_id;

		protected:
			Task m_root; // to be updated
			Blackboard m_blackboard;
		};
	}
}