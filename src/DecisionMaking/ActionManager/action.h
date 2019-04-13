#pragma once

#include <memory>

namespace AIProject
{
	namespace DecisionMaking
	{
		class Action
		{
		public:
			Action(float i_expiryTime, int i_priority = 1, bool i_canInterrupt = false);

			bool CanInterrupt() const;						// Whether this action can interrupt others
			bool CanDoBoth(const std::shared_ptr<Action> i_Action) const;	// Whether this action can run with the given action

			bool IsComplete() const;
			virtual void Execute() {}						// Called every frame

			int priority;									// Indicates importance
			int id = -1;									// Action ID
			float queuedTime;								// How long this action has been queued for
			float expiryTime;								// Wait time before discarding action

		protected:
			bool isComplete = false;
			bool canInterrupt;
		};

		bool operator < (const Action &lhs, const Action &rhs);
		bool operator <= (const Action &lhs, const Action &rhs);

		bool operator > (const Action &lhs, const Action &rhs);
		bool operator >= (const Action &lhs, const Action &rhs);

		// The following overloads compare Action id's instead of priority!

		bool operator == (const Action &lhs, const Action &rhs);
		bool operator != (const Action &lhs, const Action &rhs);
	}
}