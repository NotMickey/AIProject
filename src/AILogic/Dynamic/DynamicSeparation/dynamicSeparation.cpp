#include "dynamicSeparation.h"

AIProject::DynamicSeparation::DynamicSeparation(Boid & i_character, Boid i_targets[], const int & i_size, const float & i_threshold,
												const float & i_constant, const float & i_maxAcceleration) :
						m_character(i_character), m_targets(i_targets), m_arraySize(i_size), m_threshold(i_threshold), m_constant(i_constant),
						m_maxAcceleration(i_maxAcceleration)
{}

AIProject::DynamicSteeringOutput AIProject::DynamicSeparation::GetSteering()
{
	DynamicSteeringOutput steering;
	float strength;

	for (int i = 0; i < m_arraySize; i++)
	{
		if (m_character.m_kinematic.id == m_targets[i].m_kinematic.id)
			continue;

		ofVec2f direction = m_character.m_kinematic.position - m_targets[i].m_kinematic.position;
		float distanceSquared = direction.lengthSquared();

		if (distanceSquared < m_threshold * m_threshold)
		{
			strength = min(m_constant * distanceSquared, m_maxAcceleration);
			steering.linearAcceleration += strength * direction.getNormalized();
		}	
	}

	return steering;
}
