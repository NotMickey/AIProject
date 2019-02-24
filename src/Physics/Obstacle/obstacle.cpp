#include "obstacle.h"

AIProject::Physics::Obstacle::Obstacle(const ofVec2f &i_center, const float &i_sideLength) : m_AABB(i_center, i_sideLength)
{
	m_Id = rand() % 100000;
}

inline int AIProject::Physics::Obstacle::GetID() const
{
	return m_Id;
}

inline AIProject::Physics::AABB AIProject::Physics::Obstacle::GetAABB() const
{
	return m_AABB;
}
