#pragma once

#include "ofMain.h"

namespace AIProject
{
	struct KinematicSteeringOutput
	{
		ofVec2f velocity;
		float rotation;
	};

	struct DynamicSteeringOutput
	{
		ofVec2f linearAcceleration;
		float angularAcceleration;
	};

	class SteeringBase
	{
	public:

		virtual KinematicSteeringOutput GetSteering() = 0;

		float GetNewOrientation(const float &i_orientation, const ofVec2f &i_velocity);
	};
}

