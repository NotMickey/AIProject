#include "dynamicSeek.h"

AIProject::DynamicSeek::DynamicSeek(Boid & i_boid, const Kinematic & i_target, const float i_maxAcceleration)
										: m_boid(i_boid), m_target(i_target), m_maxAcceleration(i_maxAcceleration)
{ }

AIProject::DynamicSeek::DynamicSeek(const DynamicSeek & i_dynamicSeek)
		: m_boid(i_dynamicSeek.m_boid), m_target(i_dynamicSeek.m_target), m_maxAcceleration(i_dynamicSeek.m_maxAcceleration)
{ }

AIProject::DynamicSteeringOutput AIProject::DynamicSeek::GetSteering()
{
	DynamicSteeringOutput steering;

	steering.linearAcceleration = m_target.position - m_boid.m_kinematic.position;

	steering.linearAcceleration.normalize();
	steering.linearAcceleration *= m_maxAcceleration;

	steering.angularAcceleration = 0;

	return steering;
}
