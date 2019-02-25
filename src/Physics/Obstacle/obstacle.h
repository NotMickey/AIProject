#pragma once

#include "../CollisionDetection/collisionDataStructures.h"

namespace AIProject
{
	namespace Physics
	{
		class Obstacle
		{
		public:
			Obstacle(const ofVec2f &i_center, const float &i_sideLength);

			int GetID() const;
			AABB GetAABB() const;

		private:
			int m_Id;

			AABB m_AABB;
		};
	}
}