#include "dynamicSeparation.h"

AIProject::DynamicSeparation::DynamicSeparation(Boid & i_character, const std::vector<Boid> &i_targets, float i_threshold,
												float i_constant, float i_maxAcceleration) :
						m_character(i_character), m_vTargets(i_targets), m_threshold(i_threshold), m_constant(i_constant),
						m_maxAcceleration(i_maxAcceleration)
{}

AIProject::DynamicSteeringOutput AIProject::DynamicSeparation::GetSteering()
{
	DynamicSteeringOutput steering;
	float strength;

	for (int i = 0; i < m_vTargets.size(); i++)
	{
		if (m_character.m_kinematic.id == m_vTargets[i].m_kinematic.id)
			continue;

		ofVec2f direction = m_character.m_kinematic.position - m_vTargets[i].m_kinematic.position;
		float distanceSquared = direction.lengthSquared();

		if (distanceSquared < m_threshold * m_threshold)
		{
			strength = min(m_constant / distanceSquared, m_maxAcceleration);
			steering.linearAcceleration += strength * direction.getNormalized();
		}	
	}

	return steering;
}
