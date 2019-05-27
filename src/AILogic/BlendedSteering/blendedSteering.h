#pragma once

#include "../steeringBase.h"
#include "../../Character/boid.h"

namespace AIProject
{
	class BlendedSteering : public SteeringBase
	{
	public:
		BlendedSteering(BehaviourAndWeight i_behaviourAndWeight[], const int &i_arraySize, const float &i_maxAcceleration,
						const float &i_maxRotation);

		DynamicSteeringOutput GetSteering() override;


		BehaviourAndWeight* m_BehaviourAndWeight;

	private:
		int m_arraySize;

		float m_maxAcceleration;
		float m_maxRotation;
	};
}