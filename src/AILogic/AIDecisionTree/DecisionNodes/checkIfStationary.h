#pragma once

#include "../../../Character/boid.h"
#include "../../../DecisionMaking/DecisionTree/Decision/decisionNode.h"

namespace AIProject
{
	namespace DecisionMaking
	{
		class CheckIfStationary : public DecisionNode
		{
		public:
			CheckIfStationary(const std::shared_ptr<Boid> &i_character, DecisionNodeBase* i_trueNode = nullptr, DecisionNodeBase* i_falseNode = nullptr);

		protected:
			inline virtual bool IsTrue() override;

		private:
			std::shared_ptr<Boid> m_pCharacter;
			float m_timer;

			ofVec2f m_savedPosition;
		};
	}
}