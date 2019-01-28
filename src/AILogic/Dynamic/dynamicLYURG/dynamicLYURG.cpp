#include "dynamicLYURG.h"

#include "../DynamicAlign/dynamicAlign.h"

AIProject::DynamicLYURG::DynamicLYURG(Boid & i_character) : m_character (i_character)
{ }

AIProject::DynamicSteeringOutput AIProject::DynamicLYURG::GetSteering()
{
	DynamicSteeringOutput steering;

	if (m_character.m_kinematic.velocity.lengthSquared() < 0.0001f)
		return steering;
	else
	{
		ofVec2f direction = m_character.m_kinematic.velocity.normalize();

		Kinematic target;
		target.orientation = atan2f(direction.y, direction.x);

		DynamicAlign align(m_character, target, PI / 180 * 90, PI / 180 * 200, PI / 180 * 5, PI / 180 * 25, 0.5f);

		steering = align.GetSteering();
	}

		return steering;
}
