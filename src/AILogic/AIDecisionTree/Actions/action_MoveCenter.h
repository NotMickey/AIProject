#pragma once

#include "../../../Character/boid.h"
#include "../../../Graph/TileMap/tileMap.h"
#include "../../../DecisionMaking/DecisionTree/Action/actionNode.h"

#include "../../../Graph/Algorithm/AStar/Heuristic/eulerHeuristic.h"

namespace AIProject
{
	namespace DecisionMaking
	{
		class Action_MoveCenter : public Action
		{
		public:
			Action_MoveCenter(const std::shared_ptr<Boid> &i_character, const Graph::TileMap &i_tileMap, float i_expiryTime, int i_priority = 1, bool i_canInterrupt = false);

			virtual void Execute() override;

		private:
			std::shared_ptr<Boid> m_pCharacter;

			bool m_bIsMoving;

			int m_centerNode;

			Graph::TileMap m_tileMap;
		};
	}
}