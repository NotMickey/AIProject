#pragma once

#include "../../steeringBase.h"
#include "../../../Character/boid.h"

namespace AIProject
{
	class DynamicArrive : public SteeringBase
	{
	public:
		DynamicArrive(Boid &i_character, const Kinematic &i_target, const float &i_maxAcceleration, const float &i_maxSpeed,
						const float &i_targetRadius, const float &i_slowRadius, const float &i_timeToTarget);
		//DynamicArrive(const DynamicArrive &i_dynamicArrive);

		DynamicSteeringOutput GetSteering() override;

	private:
		float m_maxAcceleration;
		float m_maxSpeed;
		float m_targetRadius;
		float m_slowRadius;
		float m_timeToTarget;
		Kinematic m_target;
		Boid &m_character;
	};
}