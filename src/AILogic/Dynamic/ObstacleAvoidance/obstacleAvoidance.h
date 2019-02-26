#pragma once

#include "../../steeringBase.h"
#include "../../../Character/boid.h"

#include "../../../Physics/CollisionDetection/collisionDetection.h"

namespace AIProject
{
	class ObstacleAvoidance : public SteeringBase
	{
	public:
		ObstacleAvoidance(Boid &i_character, const float &i_maxAcceleration, const Physics::CollisionDetection &i_collisionDetector, const float &i_avoidDistance,
								const float &i_lookAheadDistance);

		DynamicSteeringOutput GetSteering() override;

	private:
		float m_maxAcceleration;
		float m_avoidDistance;
		float m_lookAheadDistance;

		Physics::CollisionDetection m_collisionDetector;

		Boid m_character;
	};
}