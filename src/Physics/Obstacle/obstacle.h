#pragma once

#include "../CollisionDetection/collisionDataStructures.h"

namespace AIProject
{
	namespace Physics
	{
		class Obstacle
		{
		public:
			Obstacle();
			Obstacle(const ofVec2f &i_center, const float &i_sideLength);
			Obstacle(const Obstacle &i_other);

			int GetID() const;
			AABB GetAABB() const;

			void Draw();

		private:
			int m_Id;

			float m_length;

			AABB m_AABB;

			ofVec2f m_position;
		};
	}
}