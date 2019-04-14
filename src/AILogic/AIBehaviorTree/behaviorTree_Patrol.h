#pragma once

#include "../../Character/boid.h"

#include "../../Graph/TileMap/tileMap.h"

#include "../../DecisionMaking/BehaviorTree/behaviorTree.h"
#include "../../DecisionMaking/BehaviorTree/Task/TaskBase/task.h"
#include "../../DecisionMaking/Blackboard/blackboard.h"

namespace AIProject
{
	namespace Graph
	{
		class TileMap;
	}

	namespace DecisionMaking
	{
		class BehaviorTree_Patrol : public BehaviorTree
		{
		public:
			BehaviorTree_Patrol(int i_id, const std::shared_ptr<Blackboard> &i_blackboard, const std::shared_ptr<Boid> &i_character, const Graph::TileMap &i_tileMap);

		private:
			std::shared_ptr<Boid> m_pPatrolBoid;

			Graph::TileMap m_tileMap;
		};
	}
}