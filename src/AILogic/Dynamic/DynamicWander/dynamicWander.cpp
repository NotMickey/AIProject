#include "dynamicWander.h"

#include "../DynamicFace/dynamicFace.h"

#include "../dynamicLYURG/dynamicLYURG.h"
#include "../DynamicSeek/dynamicSeek.h"

AIProject::DynamicWander::DynamicWander(Boid & i_character, const float & i_wanderOffset, const float & i_wanderRadius, const float & i_wanderRate, const float & i_maxAcceleration) :
							m_character(i_character), m_wanderOffset(i_wanderOffset), m_wanderRadius(i_wanderRadius), m_wanderRate(i_wanderRate), m_maxAcceleration(i_maxAcceleration)
{ }

AIProject::DynamicSteeringOutput AIProject::DynamicWander::GetSteering()
{
	// Update the wander orientation
	m_wanderOrientation += RandomBinomial() * m_wanderRate;

	// Calculate the combined target orientation
	float targetOrientation = m_wanderOrientation + m_character.m_kinematic.orientation;

	// Calculate the center of the wander circle
	ofVec2f target = m_character.m_kinematic.position + m_wanderOffset * m_character.GetForwardVec();

	// calculate the target location
	target += m_wanderRadius * ofVec2f(cosf(targetOrientation), sinf(targetOrientation));

	// Delegate to face
	DynamicFace face(m_character, target);

	DynamicSteeringOutput steering = face.GetSteering();

	steering.linearAcceleration = m_maxAcceleration * m_character.GetForwardVec();

	return steering;
}

AIProject::DynamicSteeringOutput AIProject::DynamicWander::GetSteeringAlt()
{
	// Update the wander orientation
	m_wanderOrientation += RandomBinomial() * m_wanderRate;

	// Calculate the combined target orientation
	float targetOrientation = m_wanderOrientation + m_character.m_kinematic.orientation;

	// Calculate the center of the wander circle
	ofVec2f targetPosition = m_character.m_kinematic.position + m_wanderOffset * m_character.GetForwardVec();

	// calculate the target location
	targetPosition += m_wanderRadius * ofVec2f(cosf(targetOrientation), sinf(targetOrientation));

	// Delegate to seek
	Kinematic target;
	target.position = targetPosition;
	DynamicSeek seek(m_character, target, m_maxAcceleration);

	DynamicSteeringOutput steering = seek.GetSteering();
	
	// Delegate to LYURG
	DynamicLYURG lyurg(m_character);

	DynamicSteeringOutput lyurgSteering = lyurg.GetSteering();

	steering.angularAcceleration = lyurgSteering.angularAcceleration;

	return steering;
}
