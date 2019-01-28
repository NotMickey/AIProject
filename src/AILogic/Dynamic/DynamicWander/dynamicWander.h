#pragma once

#include "../../steeringBase.h"
#include "../../../Character/boid.h"

namespace AIProject
{
	class DynamicWander : public SteeringBase
	{
	public:
		DynamicWander(Boid &i_character, const float &i_wanderOffset, const float &i_wanderRadius, const float &i_wanderRate,
			const float &i_maxAcceleration);
		//DynamicArrive(const DynamicArrive &i_dynamicArrive);

		DynamicSteeringOutput GetSteering();

		DynamicSteeringOutput GetSteeringAlt();

	private:
		float m_wanderOffset;
		float m_wanderRadius;

		float m_wanderOrientation = 0; // Holds current orientation of the wander target

		float m_wanderRate; // Maximum rate at which the wander orientation can change
		float m_maxAcceleration;

		Boid &m_character;
	};
}