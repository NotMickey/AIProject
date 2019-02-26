#pragma once

#include "../../steeringBase.h"
#include "../../../Character/boid.h"

namespace AIProject
{
	class CollisionAvoidance : public SteeringBase
	{
	public:
		CollisionAvoidance(Boid &i_character, Boid i_targets[], const int &i_size, const float &i_radiusOfAvoidance, const float &i_angleOfAvoidance);

		DynamicSteeringOutput GetSteering() override;

	private:
		int m_arraySize;

		Boid * m_targets;

		float m_radiusOfAvoidance;
		float m_angleOfAvoidance;

		Boid m_character;

		bool CanCollide(const Boid &i_target);
	};

}