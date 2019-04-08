#pragma once

#include <map>
#include <memory>

#include "../ActionManager/action.h"

namespace AIProject
{
	namespace DecisionMaking
	{
		enum Key
		{
			IsOpen,
			RunningChild,
			action,
			Alerted
		};

		class Blackboard
		{
		public:
			// Per node Set functions
			void Set(const Key &i_key, const bool &i_value, const int &i_treeID, const int &i_taskID);
			void Set(const Key &i_key, const int &i_value, const int &i_treeID, const int &i_taskID);

			// Per tree Set functions 
			void Set(const Key &i_key, const std::shared_ptr<Action> &i_value, const int &i_treeID);

			// Global Set functions
			void Set(const Key &i_key, const bool &i_value);

			// Get functions
			// For a per tree Get keep taskID as 0
			// For a global Get keep treeID and taskID as 0
			bool GetBool(const Key &i_key, const int &i_treeID, const int &i_taskID);
			int GetInt(const Key &i_key, const int &i_treeID, const int &i_taskID);

			// A special per tree Get function
			std::shared_ptr<Action> GetAction(const Key &i_key, const int &i_treeID);

		private:

			std::map<Key, std::map<int, bool>> boolMap;
			std::map<Key, std::map<int, int>> intMap;
			std::map<Key, std::map<int, std::shared_ptr<Action>>> actionMap;
		};
	}
}