#include "collisionDataStructures.h"

AIProject::Physics::AABB::AABB(const ofVec2f &i_center, const float &i_sideLength)
{
	float halfLength = i_sideLength / 2;

	minX = i_center.x - halfLength;
	maxX = i_center.x + halfLength;

	minY = i_center.y - halfLength;
	maxY = i_center.y + halfLength;
}