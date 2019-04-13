#pragma once

#include "../../../Character/boid.h"
#include "../../../DecisionMaking/BehaviorTree/Task/TaskBase/task.h"
#include "../../../DecisionMaking/BehaviorTree/status.h"

namespace AIProject
{
	namespace DecisionMaking
	{
		class CheckIfAlerted : public Task
		{
		public:
			CheckIfAlerted(int i_id);

		protected:
			virtual Status OnExecute(Tick &i_tick) override;
		};
	}
}
