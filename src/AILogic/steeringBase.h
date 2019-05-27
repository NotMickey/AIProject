#pragma once

#include "ofMain.h"

namespace AIProject
{
	struct DynamicSteeringOutput
	{
		ofVec2f linearAcceleration = ofVec2f();
		float angularAcceleration = 0.0f;

		void operator += (const DynamicSteeringOutput & i_rhs)
		{
			linearAcceleration += i_rhs.linearAcceleration;
			angularAcceleration += i_rhs.angularAcceleration;
		}
	};

	class SteeringBase
	{
	public:
		virtual ~SteeringBase() {}

		virtual DynamicSteeringOutput GetSteering() = 0;

		float GetNewOrientation(const float &i_orientation, const ofVec2f &i_velocity);
	};

	struct BehaviourAndWeight
	{
		SteeringBase* behaviour = nullptr;
		float weight = 0.0f;
	};

	float MapToRange(const float &i_orientation);
	float RandomBinomial();
}

