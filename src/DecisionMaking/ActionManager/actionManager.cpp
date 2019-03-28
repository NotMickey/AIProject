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
			std::sort(pendingQueue.begin(), pendingQueue.end());

			return;
		}
	}

	// New action! Add to list
	pendingQueue.push_back(i_action);

	// And sort
	std::sort(pendingQueue.begin(), pendingQueue.end());
}

void AIProject::DecisionMaking::ActionManager::Update(const float & deltaTime)
{
	// Update queued time for each action in pending
	auto it = pendingQueue.begin();

	// Might need to optimize this
	while (it != pendingQueue.end())
	{
		(*(*it))->queuedTime += deltaTime;

		if ((*(*it))->queuedTime > (*(*it))->expiryTime)
		{
			it = pendingQueue.erase(it);
		}
		else
			++it;
	}


}
