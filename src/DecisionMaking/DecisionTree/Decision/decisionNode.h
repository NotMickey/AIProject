#pragma once

#include "../decisionNodeBase.h"
#include "../../../Character/boid.h"

namespace AIProject
{
	namespace DecisionMaking
	{
		class DecisionNode : public DecisionNodeBase
		{
		public:
			DecisionNode(const Boid &i_character) : m_character(i_character) {}

			virtual DecisionNodeBase* MakeDecision() = 0; // Propogate to child!

		protected:
			DecisionNodeBase* m_pTrueNode;
			DecisionNodeBase* m_pFalseNode;

			const Boid &m_character;

			virtual DecisionNodeBase* GetBranch() = 0; // carries out the test
		};
	}
}