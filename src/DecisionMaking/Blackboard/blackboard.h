#pragma once

#include <map>
#include <memory>

#include "../ActionManager/action.h"
#include "../../Character/boid.h"
#include "../../Graph/TileMap/tileMap.h"

namespace AIProject
{
	namespace DecisionMaking
	{
		enum Key
		{
			IsOpen,
			RunningChild,
			RunningTask,
			action,
			Alerted,

		};

		class Blackboard
		{
		public:

			Blackboard(const std::shared_ptr<Boid> & i_playerBoid, const Graph::TileMap & i_tileMap) : playerBoid(i_playerBoid), tileMap(i_tileMap) {}

			// Per node Set functions
			void Set(Key i_key, bool i_value, int i_treeID, int i_taskID);
			void Set(Key i_key, int i_value, int i_treeID, int i_taskID);

			// Per tree Set functions 
			void Set(Key i_key, const std::shared_ptr<Action> &i_value, int i_treeID);

			// Global Set functions
			void Set(Key i_key, bool i_value);

			// Get functions
			// For a per tree Get keep taskID as 0
			// For a global Get keep treeID and taskID as 0
			bool GetBool(Key i_key, int i_treeID, int i_taskID) const;
			int GetInt(Key i_key, int i_treeID, int i_taskID) const ;

			// Special per tree Get & Clear functions
			std::shared_ptr<Action> GetAction(Key i_key, int i_treeID) const;
			void ClearAction(int i_treeId);

			std::shared_ptr<Boid> GetPlayer() const;

		private:

			std::shared_ptr<Boid> playerBoid;

			Graph::TileMap tileMap;

			std::map<Key, std::map<int, bool>> boolMap;
			std::map<Key, std::map<int, int>> intMap;
			std::map<Key, std::map<int, std::shared_ptr<Action>>> actionMap;
		};
	}
}