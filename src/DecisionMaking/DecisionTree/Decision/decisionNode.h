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

			virtual ~DecisionNode() {}

		protected:
			DecisionNodeBase* m_pTrueNode;
			DecisionNodeBase* m_pFalseNode;

			const Boid &m_character;

			DecisionNodeBase* GetBranch() { return (IsTrue() ? m_pTrueNode : m_pFalseNode); } // carries out the test

			inline virtual bool IsTrue() { return false; }
		};
	}
}