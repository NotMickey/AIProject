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
		class DecisionTree_Docile : public DecisionMakingBehavior
		{
		public:
			DecisionTree_Docile(const std::shared_ptr<Boid> &i_character, const Graph::TileMap &i_tileMap);

			virtual std::shared_ptr<Action> GetAction() override;

			~DecisionTree_Docile();

		private:
			DecisionNodeBase * m_pRoot;
		};
	}
}