#include "actionManager.h"

void AIProject::DecisionMaking::ActionManager::ScheduleAction(const std::shared_ptr<Action*> i_action)
{
	if (i_action == pendingQueue.Find(i_action))
		return;

	pendingQueue.Add(i_action);
}

void AIProject::DecisionMaking::ActionManager::Update(const float & deltaTime)
{
	// Update queued time for each action in pending
	std::vector<std::shared_ptr<Action*>> pending = pendingQueue.Sort();

	//for (int i = 0; i < )
}
