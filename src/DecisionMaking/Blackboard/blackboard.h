#pragma once

#include <map>

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
			// Per tree Set functions
			void Set(const Key &i_key, const bool &i_value, const int &i_treeID, const int &i_taskID);
			void Set(const Key &i_key, const int &i_value, const int &i_treeID, const int &i_taskID);

			// Per tree Get functions
			// Return type is void* so it is up to the calling entity to resolve it
			void* Get(const Key &i_key, const int &i_treeID, const int &i_taskID);

		private:

			std::map<Key, bool> boolMap;
			std::map<Key, int> intMap;
		};
	}
}