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
			virtual DecisionNodeBase* MakeDecision() override { GetBranch()->MakeDecision(); }

			virtual ~DecisionNode() {}

		protected:
			DecisionNodeBase* m_pTrueNode;
			DecisionNodeBase* m_pFalseNode;

			DecisionNodeBase* GetBranch() { return (IsTrue() ? m_pTrueNode : m_pFalseNode); } // carries out the test

			inline virtual bool IsTrue() { return false; }
		};
	}
}