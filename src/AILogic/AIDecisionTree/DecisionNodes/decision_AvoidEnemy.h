#pragma once

#include "../../../Character/boid.h"
#include "../../../DecisionMaking/DecisionTree/Decision/decisionNode.h"

namespace AIProject
{
	namespace DecisionMaking
	{
		class Decision_AvoidEnemy : public DecisionNode
		{
		public:
			Decision_AvoidEnemy(const std::shared_ptr<Boid> &i_character, const std::vector<std::shared_ptr<Boid>> & i_boids,
						DecisionNodeBase* i_trueNode = nullptr, DecisionNodeBase* i_falseNode = nullptr);

		protected:
			inline virtual bool IsTrue() override;

		private:
			std::shared_ptr<Boid> m_pCharacter;

			std::vector<std::shared_ptr<Boid>> m_vBoids;
		};
	}
}