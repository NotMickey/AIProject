#pragma once

#include "../../DecisionMaking/TreeBase/decisionMakingBehavior.h"
#include "../../DecisionMaking/DecisionTree/decisionNodeBase.h"

namespace AIProject
{
	class Boid;

	namespace Graph
	{
		class TileMap;
	}

	namespace DecisionMaking
	{
		class BoidBehaviorDocile : public DecisionMakingBehavior
		{
		public:
			BoidBehaviorDocile(const std::shared_ptr<Boid> &i_character, const Graph::TileMap &i_tileMap);

			virtual std::shared_ptr<Action> GetAction() override;

			~BoidBehaviorDocile();

		private:
			DecisionNodeBase * m_pRoot;
		};
	}
}