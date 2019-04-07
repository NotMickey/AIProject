#pragma once

namespace AIProject
{
	namespace DecisionMaking
	{
		enum Status;

		class DecisionMakingBehavior
		{
		public:
			virtual Status GetAction() = 0;

			virtual ~DecisionMakingBehavior() {}

		private:

		};
	}
}