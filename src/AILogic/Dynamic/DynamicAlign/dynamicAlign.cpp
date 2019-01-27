#include "dynamicAlign.h"

AIProject::DynamicAlign::DynamicAlign(Boid & i_character, const Kinematic & i_target, const float & i_maxRotation, const float & i_maxAngAcc,
										const float & i_targetAngle, const float & i_slowAngle, const float & i_timeToTarget) :
						m_character(i_character), m_target(i_target), m_maxRotation(i_maxRotation), m_maxAngAcc(i_maxAngAcc), m_targetAngle(i_targetAngle),
						m_slowAngle(i_slowAngle), m_timeToTarget(i_timeToTarget)
{}

AIProject::DynamicSteeringOutput AIProject::DynamicAlign::GetSteering()
{
	DynamicSteeringOutput steering;

	float rotation = m_target.orientation - m_character.m_kinematic.orientation;
	rotation = MapToRange(rotation);

	float rotationSize = fabsf(rotation);

	if (rotationSize < m_targetAngle)
	{
		steering.angularAcceleration = -0.0f;
		steering.linearAcceleration = ofVec2f(-0.0f, -0.0f);
	}

	float targetRotation;

	if (rotationSize > m_slowAngle)
	{
		targetRotation = m_maxRotation;
	}
	else
	{
		targetRotation = (rotationSize / m_slowAngle) * m_maxRotation;
	}

	targetRotation *= (rotation / rotationSize);

	float targetAngAcc = (targetRotation - m_character.m_kinematic.rotation) / m_timeToTarget;

	if (targetAngAcc > m_maxAngAcc)
	{
		targetAngAcc = m_maxAngAcc;
	}

	steering.angularAcceleration = targetAngAcc;
	steering.linearAcceleration = ofVec2f();

	return steering;
}
