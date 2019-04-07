#pragma once

#include <vector>

#include "../../Blackboard/blackboard.h"
#include "../task.h"
#include "../behaviorTree.h"

namespace AIProject
{
	namespace DecisionMaking
	{
		class Tick
		{
		public:
			Tick(const BehaviorTree* i_behaviorTree, Blackboard &i_blackBoard);

			~Tick();

			const BehaviorTree* m_pTree;
			Blackboard & m_blackboard;

		private:
			std::vector<Task> m_vOpenTasks;
		};
	}
}