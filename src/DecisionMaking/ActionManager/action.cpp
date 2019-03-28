#include "action.h"

AIProject::DecisionMaking::Action::Action(const float &i_expiryTime, const int &i_priority, const bool &i_canInterrupt)
	: priority(i_priority), expiryTime(i_expiryTime), canInterrupt(i_canInterrupt), isComplete(false)
{}

bool AIProject::DecisionMaking::Action::CanInterrupt() const
{
	return canInterrupt;
}

bool AIProject::DecisionMaking::Action::CanDoBoth(const std::shared_ptr<Action*> i_Action) const
{
	return false;
}

bool AIProject::DecisionMaking::Action::IsComplete() const
{
	return isComplete;
}
