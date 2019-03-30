#include "actionManager.h"

#include <algorithm>

void AIProject::DecisionMaking::ActionManager::ScheduleAction(const std::shared_ptr<Action*> i_action)
{
	if (pendingQueue.empty())
	{
		pendingQueue.push_back(i_action);
		return;
	}

	int i = 0;

	for (i = 0; i < pendingQueue.size(); i++)
	{
		// If an action with the given id already exists in the queue
		if (i_action == pendingQueue[i])
		{
			// replace it
			pendingQueue[i] = i_action;

			// sort the updated list
			std::sort(pendingQueue.begin(), pendingQueue.end(), std::greater<std::shared_ptr<Action*>>()); // Sort ascending. NOTE: sorting based on priority which is an integer
																					  // Thus the 3rd argument works as intended.

			return;
		}
	}

	// New action! Add to list
	pendingQueue.push_back(i_action);

	// And sort
	std::sort(pendingQueue.begin(), pendingQueue.end(), std::greater<std::shared_ptr<Action*>>());
}

void AIProject::DecisionMaking::ActionManager::Update(const float & deltaTime)
{
	//////
	// Update queued time for each action in pending
	//////
	auto it = pendingQueue.begin();

	// Might need to optimize this
	while (it != pendingQueue.end())
	{
		(*(*it))->queuedTime += deltaTime;

		// Did this pending action expire?
		if ((*(*it))->queuedTime > (*(*it))->expiryTime)
		{
			// Then remove it!
			it = pendingQueue.erase(it);
		}
		else
			++it;
	}

	//////
	// Check for interrupts
	//////
	it = pendingQueue.begin();

	while (it != pendingQueue.end())
	{
		if (activeQueue.size() > 0 && (*activeQueue[0])->priority > (*(*it))->priority)
		{
			++it;
			continue;
		}
			
		if ((*(*it))->CanInterrupt())
		{
			// Clear active queue and push this action onto it
			activeQueue.clear();
			activeQueue.push_back(*it);

			// Remove action from pending queue
			it = pendingQueue.erase(it);

			// Break because no other action in the pending queue can be of a higher priority
			break;
		}
		else
			++it;
	}
	
	//////
	// Promote actions in pending queue to active queue (this is for actions that can run concurrently)
	//////
	it = pendingQueue.begin();

	auto it2 = activeQueue.begin();

	while (it != pendingQueue.end())
	{
		it2 = activeQueue.begin();
		bool canDoBoth = true;

		while (it2 != activeQueue.end())
		{
			// Can the current pending queue action NOT run with the current active queue action?
			if (!(*(*it))->CanDoBoth(*it2))
			{
				canDoBoth = false;
				break;
			}
			
			++it2;
		}

		// If there was atleast one active queue action that the current pending action can't run with -> CONTINUE
		if (!canDoBoth)
		{
			++it;
			continue;
		}

		// We're here! That means the current pending action can run concurrently with every active action!
		activeQueue.push_back(*it);
		std::sort(activeQueue.begin(), activeQueue.end(), std::greater<std::shared_ptr<Action*>>());

		it = pendingQueue.erase(it);
	}

	//////
	// Finally RUN all active actions
	//////
	it2 = activeQueue.begin();

	while (it2 != activeQueue.end())
	{
		// Is this action complete?
		if ((*(*it2))->IsComplete())
		{
			// The remove it!
			it2 = activeQueue.erase(it2);
		}
		else
		{
			// Otherwise execute this action
			(*(*it2))->Execute();

			++it2;
		}
	}
}
