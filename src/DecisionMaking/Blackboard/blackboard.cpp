#include "blackboard.h"

void AIProject::DecisionMaking::Blackboard::Set(const Key & i_key, const bool & i_value, const int & i_treeID, const int & i_taskID)
{
	auto it = boolMap.find(i_key);
	int superID = i_treeID * 100 + i_taskID;
	
	it->second.erase(superID);
	it->second.insert(std::pair<int, bool>(superID, i_value));
}

void AIProject::DecisionMaking::Blackboard::Set(const Key & i_key, const int & i_value, const int & i_treeID, const int & i_taskID)
{
	auto it = intMap.find(i_key);
	int superID = i_treeID * 100 + i_taskID;

	it->second.erase(superID);
	it->second.insert(std::pair<int, int>(superID, i_value));
}

void AIProject::DecisionMaking::Blackboard::Set(const Key & i_key, const std::shared_ptr<Action> &i_value, const int & i_treeID)
{
	auto it = actionMap.find(i_key);
	int superID = i_treeID * 100;

	it->second.erase(superID);
	it->second.insert(std::pair<int, std::shared_ptr<Action>>(superID, i_value));
}

void AIProject::DecisionMaking::Blackboard::Set(const Key & i_key, const bool & i_value)
{
}

bool AIProject::DecisionMaking::Blackboard::GetBool(const Key & i_key, const int & i_treeID, const int & i_taskID)
{
	auto primaryKey = boolMap.find(i_key);

	if (primaryKey != boolMap.end())
	{
		int superID = i_treeID * 100 + i_taskID;
		auto it = primaryKey->second.find(superID);

		if (it != primaryKey->second.end())
			return it->second;
	}

	return false;
}

int AIProject::DecisionMaking::Blackboard::GetInt(const Key & i_key, const int & i_treeID, const int & i_taskID)
{
	auto primaryKey = intMap.find(i_key);

	if (primaryKey != intMap.end())
	{
		int superID = i_treeID * 100 + i_taskID;
		auto it = primaryKey->second.find(superID);

		if (it != primaryKey->second.end())
			return it->second;
	}

	return -1;
}

std::shared_ptr<AIProject::DecisionMaking::Action> AIProject::DecisionMaking::Blackboard::GetAction(const Key & i_key, const int & i_treeID)
{
	if (i_treeID == 0)
		return std::shared_ptr<Action>(nullptr);

	auto primaryKey = actionMap.find(i_key);

	if (primaryKey != actionMap.end())
	{
		int superID = i_treeID * 100;
		auto it = primaryKey->second.find(superID);

		if (it != primaryKey->second.end())
			return it->second;
	}

	return std::shared_ptr<Action>(nullptr);
}
