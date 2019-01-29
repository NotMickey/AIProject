#pragma once

#include "../../steeringBase.h"
#include "../../../Character/boid.h"

namespace AIProject
{
	class DynamicVelocity : public SteeringBase
	{
	public:
		DynamicVelocity(Boid &i_character, const Kinematic &i_target, const float &i_maxAcceleration, const float &i_timeToTarget);

		DynamicSteeringOutput GetSteering();

	private:
		float m_maxAcceleration;
		float m_timeToTarget;
		Kinematic m_target;
		Boid &m_character;
	};
}