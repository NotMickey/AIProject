#pragma once

#include "../../../Character/boid.h"
#include "../../../Graph/TileMap/tileMap.h"
#include "../../../DecisionMaking/BehaviorTree/Task/TaskBase/task.h"

namespace AIProject
{
	enum Status;

	namespace DecisionMaking
	{
		class ChasePlayer : public Task
		{
		public:
			ChasePlayer(int i_id, const std::shared_ptr<Boid> & i_thisBoid, const Graph::TileMap &i_tileMap);

		protected:
			virtual Status OnExecute(Tick &i_tick) override;

		private:
			std::shared_ptr<Boid> m_pBoid;

			int targetNode;

			Graph::TileMap m_tileMap;
		};
	}
}