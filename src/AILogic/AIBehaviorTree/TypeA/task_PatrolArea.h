#pragma once

#include "../../../Character/boid.h"
#include "../../../Graph/TileMap/tileMap.h"
#include "../../../DecisionMaking/BehaviorTree/Task/TaskBase/task.h"

namespace AIProject
{
	enum Status;

	namespace DecisionMaking
	{
		class Task_PatrolArea : public Task
		{
		public:
			Task_PatrolArea(int i_id, const std::shared_ptr<Boid> & i_thisBoid, const Graph::TileMap &i_tileMap, const std::vector<int> &i_nodes);

		protected:
			virtual Status OnExecute(Tick &i_tick) override;

		private:
			std::shared_ptr<Boid> m_pBoid;

			int targetNode;

			Graph::TileMap m_tileMap;

			std::vector<int> m_vPatrolNodes;
		};
	}
}