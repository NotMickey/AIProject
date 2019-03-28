#pragma once

#include <memory>

namespace AIProject
{
	namespace DecisionMaking
	{
		class Action
		{
		public:
			Action(const float &i_expiryTime, const int &i_priority = -1, const bool &i_canInterrupt = false);

			bool CanInterrupt() const;						// Whether this action can interrupt others
			bool CanDoBoth(const std::shared_ptr<Action*> i_Action) const;	// Whether this action can run with the given action

			bool IsComplete() const;
			virtual void Execute() = 0;						// Called every frame

			int priority;									// Indicates importance
			float queuedTime;								// How long this action has been queued for
			float expiryTime;								// Wait time before discarding action

		protected:
			bool isComplete;
			bool canInterrupt;
		};

		bool operator < (const Action &lhs, const Action &rhs);
		bool operator <= (const Action &lhs, const Action &rhs);

		bool operator > (const Action &lhs, const Action &rhs);
		bool operator >= (const Action &lhs, const Action &rhs);

		bool operator == (const Action &lhs, const Action &rhs);
		bool operator != (const Action &lhs, const Action &rhs);
	}
}