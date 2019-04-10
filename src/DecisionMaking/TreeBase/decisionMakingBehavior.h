#pragma once

#include <memory>

namespace AIProject
{
	namespace DecisionMaking
	{
		class Action;

		class DecisionMakingBehavior
		{
		public:
			virtual std::shared_ptr<Action> GetAction() = 0;

			virtual ~DecisionMakingBehavior() {}

		private:

		};
	}
}