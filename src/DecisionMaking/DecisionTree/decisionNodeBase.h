#pragma once

namespace AIProject
{
	namespace DecisionMaking
	{
		class DecisionNodeBase
		{
		public:
			
			virtual void MakeDecision() = 0;

			virtual ~DecisionNodeBase() {}

		private:

		};
	}
}