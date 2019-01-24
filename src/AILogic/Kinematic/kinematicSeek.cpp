#include "kinematicSeek.h"

AIProject::KinematicSeek::KinematicSeek(Boid & i_boid, const Kinematic & i_target, const float i_maxSpeed)
										: m_boid(i_boid), m_target(i_target), m_maxSpeed(i_maxSpeed)
{ }

AIProject::KinematicSeek::KinematicSeek(const KinematicSeek & i_kinematicSeek)
		: m_boid(i_kinematicSeek.m_boid), m_target(i_kinematicSeek.m_target), m_maxSpeed(i_kinematicSeek.m_maxSpeed)
{ }

AIProject::KinematicSteeringOutput AIProject::KinematicSeek::GetSteering()
{
	KinematicSteeringOutput steering;

	steering.velocity = m_target.position - m_boid.m_kinematic.position;

	steering.velocity.normalize();
	steering.velocity *= m_maxSpeed;

	steering.rotation = 0;

	m_boid.m_kinematic.orientation = GetNewOrientation(m_boid.m_kinematic.orientation, steering.velocity);

	return steering;
}
