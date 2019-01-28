#pragma once

#include "ofMain.h"

namespace AIProject
{
	struct DynamicSteeringOutput
	{
		ofVec2f linearAcceleration = ofVec2f();
		float angularAcceleration = 0.0f;
	};

	class SteeringBase
	{
	public:

		virtual DynamicSteeringOutput GetSteering() = 0;

		float GetNewOrientation(const float &i_orientation, const ofVec2f &i_velocity);
	};

	float MapToRange(const float &i_orientation);
	float RandomBinomial();
}

