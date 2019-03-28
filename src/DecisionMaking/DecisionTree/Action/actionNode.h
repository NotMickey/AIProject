#pragma once

#include "../decisionNodeBase.h"

namespace AIProject
{
	namespace DecisionMaking
	{
		class ActionNode : public DecisionNodeBase 
		{
		public:
			inline virtual DecisionNodeBase* MakeDecision() override { return this; }



		private:

		};
	}
}