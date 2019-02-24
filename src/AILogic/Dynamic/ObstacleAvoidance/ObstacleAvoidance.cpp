#include "obstacleAvoidance.h"

#include "../DynamicSeek/dynamicSeek.h"

AIProject::ObstacleAvoidance::ObstacleAvoidance(Boid & i_character, const float & i_maxAcceleration, const Physics::CollisionDetection & i_collisionDetector,
														const float & i_avoidDistance, const float & i_lookAheadDistance) :
							m_character(i_character), m_maxAcceleration(i_maxAcceleration), m_collisionDetector(i_collisionDetector), m_avoidDistance(i_avoidDistance),
							m_lookAheadDistance(i_lookAheadDistance)
{}

AIProject::DynamicSteeringOutput AIProject::ObstacleAvoidance::GetSteering()
{
	Physics::Ray rayCast;
	rayCast.direction = m_character.GetForwardVec();
	rayCast.origin = m_character.m_kinematic.position;

	Physics::Collision detectedCollsion;

	if (!m_collisionDetector.GetCollision(rayCast, m_lookAheadDistance, detectedCollsion))
		return DynamicSteeringOutput();

	Kinematic target;
	target.position = detectedCollsion.position + (detectedCollsion.normal * m_avoidDistance);

	DynamicSeek seek(m_character, target, m_maxAcceleration);

	DynamicSteeringOutput steering = seek.GetSteering();

	return steering;
}
