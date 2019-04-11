#pragma once

#include "../../../Character/boid.h"

#include "../../../DecisionMaking/DecisionTree/Decision/decisionNode.h"

namespace AIProject
{
	namespace DecisionMaking
	{
		class EdgeCollisionCheck : public DecisionNode
		{
		public:
			EdgeCollisionCheck(const std::shared_ptr<Boid> &i_character, DecisionNodeBase* i_trueNode = nullptr, DecisionNodeBase* i_falseNode = nullptr);

		protected:
			inline virtual bool IsTrue() override;

		private:
			std::shared_ptr<Boid> m_pCharacter;
		};
	}
}
