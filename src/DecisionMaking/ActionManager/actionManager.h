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
			void ScheduleAction(const std::shared_ptr<Action*> i_action);
			void Update(const float &deltaTime);

		private:
			AIProject::Graph::Heap<std::shared_ptr<Action*>> pendingQueue;  // A priority queue of pending actions

			std::vector<std::shared_ptr<Action*>> activeQueue;              // A list of active actions being executed simultaneously. Order does not matter.
		};
	}
}