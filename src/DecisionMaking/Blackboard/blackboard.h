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
			RunningChild
		};

		class Blackboard
		{
		public:
			// Per node Set functions
			void Set(const Key &i_key, const bool &i_value, const int &i_treeID, const int &i_taskID);
			void Set(const Key &i_key, const int &i_value, const int &i_treeID, const int &i_taskID);

			// Per node Get functions
			// Return type is void* so it is up to the calling entity to resolve it
			void* Get(const Key &i_key, const int &i_treeID, const int &i_taskID);

			// Per tree Set functions 
			void SetAction(const Key &i_key, const std::shared_ptr<Action> &i_action, const int &i_treeID);

			// Per tree Get functions
			std::shared_ptr<Action> GetAction(const Key &i_key, const int &i_treeID);

		private:

			std::map<Key, bool> boolMap;
			std::map<Key, int> intMap;
			std::map<Key, std::shared_ptr<Action>> actionMap;
		};
	}
}