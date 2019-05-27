#pragma once

#include "../decisionNodeBase.h"

namespace AIProject
{
	namespace DecisionMaking
	{
		class DecisionNode : public DecisionNodeBase
		{
		public:
			DecisionNode(DecisionNodeBase* i_trueNode = nullptr, DecisionNodeBase* i_falseNode = nullptr)
				: m_pTrueNode(i_trueNode), m_pFalseNode(i_falseNode) {}

			virtual DecisionNodeBase* MakeDecision() override
			{
				DecisionNodeBase* node = GetBranch();

				if (node == nullptr)
					return nullptr;

				return node->MakeDecision();
			}

			virtual ~DecisionNode() 
			{
				if (m_pTrueNode)
				{
					delete m_pTrueNode;
					m_pTrueNode = nullptr;
				}
					
				if (m_pFalseNode)
				{
					delete m_pFalseNode;
					m_pFalseNode = nullptr;
				}
			}

		protected:
			DecisionNodeBase* m_pTrueNode;
			DecisionNodeBase* m_pFalseNode;

			DecisionNodeBase* GetBranch() { return (IsTrue() ? m_pTrueNode : m_pFalseNode); } // carries out the test

			inline virtual bool IsTrue() { return false; }
		};
	}
}