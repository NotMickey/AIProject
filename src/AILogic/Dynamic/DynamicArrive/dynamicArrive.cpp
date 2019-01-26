#include "dynamicArrive.h"

AIProject::DynamicArrive::DynamicArrive(Boid & i_character, const Kinematic & i_target, const float & i_maxAcceleration, const float & i_maxSpeed,
	const float & i_targetRadius, const float & i_slowRadius, const float & i_timeToTarget) :
	m_character(i_character), m_target(i_target), m_maxAcceleration(i_maxAcceleration), m_maxSpeed(i_maxSpeed), m_targetRadius(i_targetRadius),
	m_slowRadius(i_slowRadius), m_timeToTarget(i_timeToTarget)
{}

AIProject::DynamicSteeringOutput AIProject::DynamicArrive::GetSteering()
{
	DynamicSteeringOutput steering;

	ofVec2f direction = m_target.position - m_character.m_kinematic.position;
	float distance = direction.length();

	if (distance < m_targetRadius)
	{
		steering.linearAcceleration = ofVec2f(-0.0f, -0.0f);
		steering.angularAcceleration = 0.0f;

		return steering;
	}

	float targetSpeed = 0.0f;

	if (distance > m_slowRadius)
	{
		targetSpeed = m_maxSpeed;
	}
	else
	{
		targetSpeed = m_maxSpeed * (distance / m_slowRadius);
	}

	ofVec2f targetVelocity = direction.normalize() * targetSpeed;

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
