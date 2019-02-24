#include "collisionDetection.h"

AIProject::Physics::CollisionDetection::CollisionDetection(Obstacle i_obstacles[], const int & i_numOfObstacles) :
										m_obstacles(i_obstacles), m_numOfObstacles(i_numOfObstacles)
{}

bool AIProject::Physics::CollisionDetection::GetCollision(const Ray & i_rayVector, const float &i_length, Collision &o_collision) const
{
	for (int i = 0; i < m_numOfObstacles; i++)
	{
		if (Intersect(i_rayVector, i_length, m_obstacles[i], o_collision))
			return true;
	}

	return false;
}

bool AIProject::Physics::CollisionDetection::Intersect(const Ray & i_rayVector, const float & i_length, const Obstacle & i_obstacle, Collision &o_collision) const
{
	float maxS = 0.0f;
	float minT = i_length;

	float recipX = 1.0f / i_rayVector.direction.x;
	float recipY = 1.0f / i_rayVector.direction.y;

	// x length along ray from its origin to left face of AABB
	float T1 = (i_obstacle.GetAABB().minX - i_rayVector.origin.x) * recipX;

	// x length along ray from its origin to right face of AABB 
	float T2 = (i_obstacle.GetAABB().maxX - i_rayVector.origin.x) * recipX;

	float T3 = (i_obstacle.GetAABB().minY - i_rayVector.origin.y) * recipY;

	float T4 = (i_obstacle.GetAABB().maxY - i_rayVector.origin.y) * recipY;

	float minT = max(min(T1, T2), min(T3, T4));

	float maxT = min(max(T1, T2), max(T3, T4));

	// Ray is intersecting AABB but in the opposite direction 
	if (maxT < 0)
	{
		return false;
	}

	// Ray does not intersect AABB
	if (minT > maxT)
	{
		return false;
	}

	// Intersection! And minT is the vector length of ray to point of contact with AABB

	// Calculate collision normal
	o_collision.normal = GetNormal(T1, T2, T3, T4, minT);

	// Calculate collision position
	o_collision.position.x = i_rayVector.origin.x + i_rayVector.direction.x * minT;
	o_collision.position.y = i_rayVector.origin.y + i_rayVector.direction.y * minT;

	return true;
}

ofVec2f AIProject::Physics::CollisionDetection::GetNormal(const float & T1, const float & T2, const float & T3, const float & T4, const float & minT) const
{
	ofVec2f collisionNormal;

	if (minT == T1)
		collisionNormal = ofVec2f(-1.0f, 0.0f);
	else if (minT == T2)
		collisionNormal = ofVec2f(1.0f, 0.0f);
	else if (minT == T3)
		collisionNormal = ofVec2f(0.0f, -1.0f);
	else
		collisionNormal = ofVec2f(0.0f, 1.0f);

	return collisionNormal;
}
