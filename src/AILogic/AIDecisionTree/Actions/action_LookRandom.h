#pragma once

#include "../../../Character/boid.h"
#include "../../../Graph/TileMap/tileMap.h"
#include "../../../DecisionMaking/DecisionTree/Action/actionNode.h"

namespace AIProject
{
	namespace DecisionMaking
	{
		class Action_LookRandom : public Action
		{
		public:
			Action_LookRandom(const std::shared_ptr<Boid> &i_character, const Graph::TileMap &i_tileMap, float i_expiryTime, int i_priority = 1, bool i_canInterrupt = false);

			virtual void Execute() override;

		private:
			void SetNewLookPosition();

			std::shared_ptr<Boid> m_pCharacter;

			float m_timer;
			ofVec2f m_lookPosition;

			Graph::TileMap m_tileMap;
		};
	}
}