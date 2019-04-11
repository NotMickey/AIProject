#pragma once

#include "../../../Character/boid.h"
#include "../../../Graph/TileMap/tileMap.h"
#include "../../../DecisionMaking/DecisionTree/Action/actionNode.h"

namespace AIProject
{
	namespace DecisionMaking
	{
		class MoveRandom : public Action
		{
		public:
			MoveRandom(const std::shared_ptr<Boid> &i_character, const Graph::TileMap &i_tileMap, float i_expiryTime, int i_priority = 1, bool i_canInterrupt = false);

			virtual void Execute() override;

		private:
			std::shared_ptr<Boid> m_pCharacter;

			Graph::TileMap m_tileMap;
		};
	}
}