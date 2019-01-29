#include "blendedSteering.h"

AIProject::BlendedSteering::BlendedSteering(BehaviourAndWeight i_behaviourAndWeight[], const int & i_arraySize,
												const float & i_maxAcceleration, const float & i_maxRotation) :
							m_BehaviourAndWeight(i_behaviourAndWeight), m_arraySize(i_arraySize), m_maxAcceleration(i_maxAcceleration),
							m_maxRotation(i_maxRotation)
{ }

AIProject::DynamicSteeringOutput AIProject::BlendedSteering::GetSteering()
{
	DynamicSteeringOutput steering;

	DynamicSteeringOutput adjustedSteering;

	for (int i = 0; i < m_arraySize; i++)
	{
		adjustedSteering = m_BehaviourAndWeight[i].behaviour->GetSteering();

		adjustedSteering.angularAcceleration *= m_BehaviourAndWeight[i].weight;
		adjustedSteering.linearAcceleration *= m_BehaviourAndWeight[i].weight;

		steering.angularAcceleration += adjustedSteering.angularAcceleration;
		steering.linearAcceleration += adjustedSteering.linearAcceleration;
	}

	return steering;
}
