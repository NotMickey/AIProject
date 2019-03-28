#pragma once

namespace AIProject
{
	namespace DecisionMaking
	{
		class DecisionNodeBase
		{
		public:
			
			virtual DecisionNodeBase* MakeDecision() = 0;

			virtual ~DecisionNodeBase() {}

		private:

		};
	}
}