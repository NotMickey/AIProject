#pragma once

#include "../../../Character/boid.h"
#include "../../../DecisionMaking/BehaviorTree/Task/TaskBase/task.h"
#include "../../../DecisionMaking/BehaviorTree/status.h"

namespace AIProject
{
	namespace DecisionMaking
	{
		class PlayerInRange : public Task
		{
		public:
			PlayerInRange(const int &i_id, const float &i_minDist, const Boid &i_thisBoid);

		protected:
			virtual Status OnExecute(Tick &i_tick) override;

		private:
			float m_minDistance;
			const Boid & m_thisBoid;
		};
	}
}