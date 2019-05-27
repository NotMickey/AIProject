#pragma once

#include "../../steeringBase.h"
#include "../../../Character/boid.h"

namespace AIProject
{
	class CollisionAvoidance : public SteeringBase
	{
	public:
		CollisionAvoidance(Boid &i_character, Boid i_targets[], int i_size, float i_radiusOfAvoidance, float i_angleOfAvoidance);

		DynamicSteeringOutput GetSteering() override;

	private:
		bool CanCollide(const Boid &i_target);

		int m_arraySize;

		Boid * m_targets;

		float m_radiusOfAvoidance;
		float m_angleOfAvoidance;

		Boid &m_character;

		std::vector<Boid> m_vTargets;
	};

}