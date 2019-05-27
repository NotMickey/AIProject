#include "action.h"

AIProject::DecisionMaking::Action::Action(float i_expiryTime, int i_priority, bool i_canInterrupt)
	: priority(i_priority), expiryTime(i_expiryTime), canInterrupt(i_canInterrupt)
{
	queuedTime = 0.0f;
}

bool AIProject::DecisionMaking::Action::CanInterrupt() const
{
	return canInterrupt;
}

bool AIProject::DecisionMaking::Action::CanDoBoth(const std::shared_ptr<Action> i_Action) const
{
	/*if (this->id == i_Action->id)
		return false;

	return true;*/

	return false;
}

bool AIProject::DecisionMaking::Action::IsComplete() const
{
	return isComplete;
}

void AIProject::DecisionMaking::Action::ResetAction()
{
	isComplete = false;
	queuedTime = 0.0f;
}

bool AIProject::DecisionMaking::operator<(const Action & lhs, const Action & rhs)
{
	return (lhs.priority < rhs.priority);
}

bool AIProject::DecisionMaking::operator<=(const Action & lhs, const Action & rhs)
{
	return (lhs.priority <= rhs.priority);
}

bool AIProject::DecisionMaking::operator>(const Action & lhs, const Action & rhs)
{
	return !(lhs < rhs);
}

bool AIProject::DecisionMaking::operator>=(const Action & lhs, const Action & rhs)
{
	return !(lhs <= rhs);
}

bool AIProject::DecisionMaking::operator==(const Action & lhs, const Action & rhs)
{
	return (lhs.id == rhs.id);
}

bool AIProject::DecisionMaking::operator!=(const Action & lhs, const Action & rhs)
{
	return !(lhs == rhs);
}
