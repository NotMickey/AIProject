#pragma once

#include "../../../Character/boid.h"
#include "../../../Graph/TileMap/tileMap.h"
#include "../../../DecisionMaking/BehaviorTree/Task/TaskBase/task.h"

namespace AIProject
{
	enum Status;

	namespace DecisionMaking
	{
		class Task_SetColor : public Task
		{
		public:
			Task_SetColor(int i_id, const std::shared_ptr<Boid> & i_thisBoid);

		protected:
			virtual Status OnExecute(Tick &i_tick) override;

		private:
			std::shared_ptr<Boid> m_pBoid;
		};
	}
}