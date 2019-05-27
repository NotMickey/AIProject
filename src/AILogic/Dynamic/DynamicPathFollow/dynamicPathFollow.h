#pragma once

#include "../../steeringBase.h"
#include "../../../Character/boid.h"

#include <vector>

namespace AIProject
{
	class DynamicPathFollow : public SteeringBase
	{
	public:
		DynamicPathFollow(Boid &i_character, const float &i_maxSpeed, const float &i_maxAcceleration, const float &i_slowRadius,
							const float &i_targetRadius, const std::vector<ofVec2f> &i_waypoints);
		
		DynamicSteeringOutput GetSteering() override;

	private:
		float m_maxSpeed;
		float m_maxAcceleration;
		float m_slowRadius;
		float m_targetRadius;

		Boid & m_character;

		Kinematic kinematic;

		std::vector<ofVec2f> m_waypoints;

	};
}