#include "collisionAvoidance.h"

#include "../DynamicSeparation/dynamicSeparation.h"

AIProject::CollisionAvoidance::CollisionAvoidance(Boid & i_character, Boid i_targets[], int i_size, float i_radiusOfAvoidance, float i_angleOfAvoidance) :
								m_character(i_character), m_targets(i_targets), m_arraySize(i_size), m_radiusOfAvoidance(i_radiusOfAvoidance), m_angleOfAvoidance(i_angleOfAvoidance)
{}


AIProject::DynamicSteeringOutput AIProject::CollisionAvoidance::GetSteering()
{
	DynamicSteeringOutput steering;

	m_vTargets.clear();

	for (int i = 0; i < m_arraySize; i++)
	{
		if (CanCollide(m_targets[i]))
			m_vTargets.push_back(m_targets[i]);
	}

	DynamicSeparation seperation(m_character, m_vTargets, m_radiusOfAvoidance, 5, 50);

	steering = seperation.GetSteering();
	
	return steering;
}

bool AIProject::CollisionAvoidance::CanCollide(const Boid & i_target)
{
	if (m_character.m_kinematic.id == i_target.m_kinematic.id)
		return false;

	int squareDistance = m_character.m_kinematic.position.squareDistance(i_target.m_kinematic.position);

	if (squareDistance > m_radiusOfAvoidance * m_radiusOfAvoidance)
		return false;

	ofVec2f unitVector = i_target.m_kinematic.position - m_character.m_kinematic.position;
	unitVector = unitVector.getNormalized();

	if (unitVector.dot(m_character.GetForwardVec()) < cosf(m_angleOfAvoidance))
		return false;

	return true;
}
