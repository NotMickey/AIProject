#pragma once

#include<vector>

#include "action.h"
#include "../../Graph/DataStructures/Heap/heap.h"

namespace AIProject
{
	namespace DecisionMaking
	{
		class ActionManager
		{
		public:
			void ScheduleAction(const std::shared_ptr<Action> &i_action);
			void Update(float i_deltaTime);

		private:
			std::vector<std::shared_ptr<Action>> pendingQueue;				// A priority queue of pending actions

			std::vector<std::shared_ptr<Action>> activeQueue;              // A priority queue of active actions being executed simultaneously.
		};
	}
}