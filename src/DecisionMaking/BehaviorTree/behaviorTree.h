#pragma once

#include "../TreeBase/decisionMakingBehavior.h"

#include "Task/TaskBase/task.h"
#include "../Blackboard/blackboard.h"

namespace AIProject
{
	namespace DecisionMaking
	{
		class BehaviorTree : public DecisionMakingBehavior
		{
		public:
			BehaviorTree(int i_id, const std::shared_ptr<Blackboard> &i_blackboard);

			virtual std::shared_ptr<Action> GetAction() override;

			virtual ~BehaviorTree();

			int m_id;

		protected:
			Task * m_pRoot;
			std::shared_ptr<Blackboard> m_pBlackboard;
		};
	}
}