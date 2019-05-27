#include "blackboard.h"

void AIProject::DecisionMaking::Blackboard::Set(Key i_key, bool i_value, int i_treeID, int i_taskID)
{
	auto it = boolMap.find(i_key);
	int superID = i_treeID * 100 + i_taskID;
	
	if (it != boolMap.end())
	{
		it->second.erase(superID);
		it->second.emplace(superID, i_value);
	}

	std::map<int, bool> temp;
	temp.emplace(superID, i_value);

	boolMap.emplace(i_key, temp);
}

void AIProject::DecisionMaking::Blackboard::Set(Key i_key, int i_value, int i_treeID,  int i_taskID)
{
	auto it = intMap.find(i_key);
	int superID = i_treeID * 100 + i_taskID;

	if (it != intMap.end())
	{
		it->second.erase(superID);
		it->second.emplace(superID, i_value);
	}
		
	std::map<int, int> temp;
	temp.emplace(superID, i_value);

	intMap.emplace(i_key, temp);
}

void AIProject::DecisionMaking::Blackboard::Set(Key i_key, const std::shared_ptr<Action> &i_value, int i_treeID)
{
	auto it = actionMap.find(i_key);
	int superID = i_treeID * 100;

	if(it != actionMap.end())
	{
		it->second.erase(superID);
		it->second.emplace(superID, i_value);
	}

	std::map<int, std::shared_ptr<Action>> temp;
	temp.emplace(superID, i_value);

	actionMap.emplace(i_key, temp);
}

void AIProject::DecisionMaking::Blackboard::Set(Key i_key, bool i_value)
{
}

bool AIProject::DecisionMaking::Blackboard::GetBool(Key i_key, int i_treeID, int i_taskID) const
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

int AIProject::DecisionMaking::Blackboard::GetInt(Key i_key, int i_treeID, int i_taskID) const 
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

std::shared_ptr<AIProject::DecisionMaking::Action> AIProject::DecisionMaking::Blackboard::GetAction(Key i_key, int i_treeID) const
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

void AIProject::DecisionMaking::Blackboard::ClearAction(int i_treeId)
{
	if (i_treeId == 0)
		return;

	auto primaryKey = actionMap.find(Key::action);

	if (primaryKey != actionMap.end())
	{
		int superID = i_treeId * 100;
		auto it = primaryKey->second.find(superID);

		if (it != primaryKey->second.end())
			it->second.reset();
	}
}

std::shared_ptr<AIProject::Boid> AIProject::DecisionMaking::Blackboard::GetPlayer() const
{
	return playerBoid;
}
