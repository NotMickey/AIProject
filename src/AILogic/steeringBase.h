#pragma once

#include "ofMain.h"

namespace AIProject
{
	struct DynamicSteeringOutput
	{
		ofVec2f linearAcceleration;
		float angularAcceleration;
	};

	class SteeringBase
	{
	public:

		virtual DynamicSteeringOutput GetSteering() = 0;

		float GetNewOrientation(const float &i_orientation, const ofVec2f &i_velocity);
	};
}

