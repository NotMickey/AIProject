#include "blackboard.h"

void AIProject::DecisionMaking::Blackboard::Set(const Key & i_key, const bool & i_value, const int & i_treeID, const int & i_taskID)
{
	boolMap.erase(i_key);
	boolMap.insert(std::pair<Key, int>(i_key, i_value));
}

void AIProject::DecisionMaking::Blackboard::Set(const Key & i_key, const int & i_value, const int & i_treeID, const int & i_taskID)
{
	intMap.erase(i_key);
	intMap.insert(std::pair<Key, int>(i_key, i_value));
}

void * AIProject::DecisionMaking::Blackboard::Get(const Key & i_key, const int & i_treeID, const int & i_taskID)
{
	auto it = boolMap.find(i_key);
	if (it != boolMap.end())
		return &(it->second);

	auto it2 = intMap.find(i_key);
	if (it2 != intMap.end())
		return &(it->second);

	return nullptr;
}

void AIProject::DecisionMaking::Blackboard::SetAction(const Key & i_key, const std::shared_ptr<Action> &i_action, const int & i_treeID)
{
}

std::shared_ptr<AIProject::DecisionMaking::Action> AIProject::DecisionMaking::Blackboard::GetAction(const Key & i_key, const int & i_treeID)
{
	return std::shared_ptr<Action>();
}
