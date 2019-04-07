#pragma once

#include "TreeBase/decisionMakingBehavior.h"

#include "task.h"
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
			Task m_root;
			Blackboard m_blackboard;
		};
	}
}