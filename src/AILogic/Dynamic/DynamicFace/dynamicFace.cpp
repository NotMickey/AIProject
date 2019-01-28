#include "dynamicFace.h"

#include "../DynamicAlign/dynamicAlign.h"

AIProject::DynamicFace::DynamicFace(Boid & i_character, const ofVec2f & i_targetPosition, const float & i_maxRotation, const float & i_maxAngAcc,
										const float & i_targetAngle, const float & i_slowAngle, const float & i_timeToTarget) :
					m_character(i_character), m_targetPosition(i_targetPosition), m_maxRotation(i_maxRotation), m_maxAngAcc(i_maxAngAcc),
					m_targetAngle(i_targetAngle), m_slowAngle(i_slowAngle), m_timeToTarget(i_timeToTarget)
{ }

AIProject::DynamicSteeringOutput AIProject::DynamicFace::GetSteering()
{
	DynamicSteeringOutput steering;

	ofVec2f direction = m_targetPosition - m_character.m_kinematic.position;
	direction.normalize();

	if (direction == ofVec2f(0.0f, 0.0f))
	{
		steering.angularAcceleration = 0.0f;
		steering.linearAcceleration = ofVec2f(0.0f, 0.0f);
	}
	else
	{
		Kinematic target;
		target.orientation = atan2f(direction.y, direction.x);

		DynamicAlign align(m_character, target, m_maxRotation, m_maxAngAcc, m_targetAngle, m_slowAngle, m_timeToTarget);

		steering = align.GetSteering();
	}

	return steering;
}
