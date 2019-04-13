#pragma once

#include "../../../Character/boid.h"
#include "../../../DecisionMaking/BehaviorTree/Task/TaskBase/task.h"
//

namespace AIProject
{
	enum Status;

	namespace DecisionMaking
	{
		class ChasePlayer : public Task
		{
		public:
			ChasePlayer(int i_id);

		protected:
			virtual Status OnExecute(Tick &i_tick) override;

		private:
			int targetNode;
		};
	}
}