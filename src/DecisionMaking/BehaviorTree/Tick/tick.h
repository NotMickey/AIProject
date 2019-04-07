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

			void OpenTask(const Task &i_task);
			void CloseTask(const Task &i_task);

			// Debug functions for logging
			void EnterTask(const Task &i_task) const;
			void ExecuteTask(const Task &i_task) const;
			void ExitTask(const Task &i_task) const;

			~Tick();

			const BehaviorTree* m_pTree;
			Blackboard & m_blackboard;

		private:
			std::vector<Task> m_vOpenTasks;
		};
	}
}