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
			action
		};

		class Blackboard
		{
		public:
			// Per node Set functions
			void Set(const Key &i_key, const bool &i_value, const int &i_treeID, const int &i_taskID);
			void Set(const Key &i_key, const int &i_value, const int &i_treeID, const int &i_taskID);

			// Per tree Set functions 
			void Set(const Key &i_key, const std::shared_ptr<Action> &i_value, const int &i_treeID);

			// Per node Get functions
			bool GetBool(const Key &i_key, const int &i_treeID, const int &i_taskID);
			int GetInt(const Key &i_key, const int &i_treeID, const int &i_taskID);

			// Per tree Get functions
			std::shared_ptr<Action> GetAction(const Key &i_key, const int &i_treeID);

		private:

			std::map<Key, std::map<int, bool>> boolMap;
			std::map<Key, std::map<int, int>> intMap;
			std::map<Key, std::map<int, std::shared_ptr<Action>>> actionMap;
		};
	}
}