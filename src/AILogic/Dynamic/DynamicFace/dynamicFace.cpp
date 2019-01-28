#include "dynamicFace.h"

#include "../DynamicAlign/dynamicAlign.h"

AIProject::DynamicFace::DynamicFace(Boid & i_character, const ofVec2f & i_targetPosition) :
									m_character(i_character), m_targetPosition(i_targetPosition)
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

		DynamicAlign align(m_character, target, PI / 180 * 90, PI / 180 * 200, PI / 180 * 5, PI / 180 * 25, 0.5f);

		steering = align.GetSteering();
	}

	return steering;
}
