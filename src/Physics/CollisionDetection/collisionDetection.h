#pragma once

#include "../Obstacle/obstacle.h"

namespace AIProject
{
	namespace Physics
	{
		class CollisionDetection
		{
		public:
			CollisionDetection(Obstacle i_obstacles[], const int &i_numOfObstacles);

			bool GetCollision(const Ray& i_rayVector, const float &i_length, Collision &o_collision) const;

		private:
			Obstacle* m_obstacles;
			int m_numOfObstacles;

			bool Intersect(const Ray& i_rayVector, const float &i_length, const Obstacle &i_obstacle, Collision &o_collision) const;
			ofVec2f GetNormal(const float &T1, const float &T2, const float &T3, const float &T4, const float &minT) const;
		};
	}
}