#pragma once

#include "../../Character/boid.h"

#include "../../Graph/TileMap/tileMap.h"

#include "../../DecisionMaking/TreeBase/decisionMakingBehavior.h"
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
		class BehaviorTree_Patrol : public DecisionMakingBehavior
		{
		public:
			BehaviorTree_Patrol(const std::shared_ptr<Boid> &i_character, const Graph::TileMap &i_tileMap, const std::shared_ptr<Blackboard> &i_blackboard);

			virtual std::shared_ptr<Action> GetAction() override;

			~BehaviorTree_Patrol();

		private:
			Task * m_pRoot;

			std::shared_ptr<Blackboard> m_pBlackboard;
			std::shared_ptr<Boid> m_pPatrolBoid;

			Graph::TileMap m_tileMap;
		};
	}
}