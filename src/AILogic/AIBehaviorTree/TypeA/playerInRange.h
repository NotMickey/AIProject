#pragma once

#include "../../../Character/boid.h"
#include "../../../DecisionMaking/BehaviorTree/Task/TaskBase/task.h"

namespace AIProject
{
	namespace DecisionMaking
	{
		enum Status;

		class PlayerInRange : public Task
		{
		public:
			PlayerInRange(int i_id, float i_minDist, const std::shared_ptr<Boid> &i_thisBoid);

		protected:
			virtual Status OnExecute(Tick &i_tick) override;

		private:
			float m_minDistance;
			std::shared_ptr<Boid> m_pThisBoid;
		};
	}
}