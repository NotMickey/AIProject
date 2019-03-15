#pragma once

#include "../decisionNodeBase.h"

namespace AIProject
{
	namespace DecisionMaking
	{
		class ActionNode : public DecisionNodeBase 
		{
		public:
			virtual void MakeDecision() override;

		private:

		};
	}
}