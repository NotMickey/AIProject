#pragma once

#include "ofMain.h"

namespace AIProject
{
	namespace Physics
	{
		struct Ray
		{
			ofVec2f direction;
			ofVec2f origin;
		};

		struct Collision
		{
			ofVec2f position;
			ofVec2f normal;
		};

		struct AABB
		{
			AABB(const ofVec2f &i_center, const float &i_sideLength);

			float minX, minY, maxX, maxY;
		};
	}
}