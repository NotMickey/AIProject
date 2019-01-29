#include "dynamicVelocity.h"

AIProject::DynamicVelocity::DynamicVelocity(Boid & i_character, const Kinematic & i_target, const float & i_maxAcceleration, const float & i_timeToTarget) :
	m_character(i_character), m_target(i_target), m_maxAcceleration(i_maxAcceleration), m_timeToTarget(i_timeToTarget)
{}

AIProject::DynamicSteeringOutput AIProject::DynamicVelocity::GetSteering()
{
	DynamicSteeringOutput steering;

	ofVec2f targetVelocity = m_target.velocity;

	steering.linearAcceleration = targetVelocity - m_character.m_kinematic.velocity;
	steering.linearAcceleration /= m_timeToTarget;

	if (steering.linearAcceleration.lengthSquared() > m_maxAcceleration * m_maxAcceleration)
	{
		steering.linearAcceleration.normalize();
		steering.linearAcceleration *= m_maxAcceleration;
	}

	steering.angularAcceleration = 0;

	return steering;
}
