#pragma once

#include "../../Blackboard/blackboard.h"
#include "../Task/TaskBase/task.h"
#include "../behaviorTree.h"

namespace AIProject
{
	namespace DecisionMaking
	{
		class Tick
		{
		public:
			Tick(const DecisionMakingBehavior* i_behaviorTree, const std::shared_ptr<Blackboard> &i_blackBoard);

			// Cannot pass Task as weak or shared pointers because it is a "this" pointer
			void OpenTask(Task* const i_task);
			void CloseTask(Task* const i_task);

			// Debug functions for logging
			void EnterTask(Task* const i_task) const;
			void ExecuteTask(Task* const i_task) const;
			void ExitTask(Task* const i_task) const;

			~Tick();

			const DecisionMakingBehavior* m_pTree;
			std::shared_ptr<Blackboard> m_pBlackboard;

		private:
			std::vector<Task*> m_vOpenTasks;
		};
	}
}