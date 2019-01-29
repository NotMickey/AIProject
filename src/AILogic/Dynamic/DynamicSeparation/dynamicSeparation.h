#pragma once

#include "../../steeringBase.h"
#include "../../../Character/boid.h"

namespace AIProject
{
	class DynamicSeparation : public SteeringBase
	{
	public:
		DynamicSeparation(Boid &i_character, Boid i_targets[], const int &i_size, const float &i_threshold, const float &i_constant,
			const float &i_maxAcceleration);

		DynamicSteeringOutput GetSteering();

	private:
		int m_arraySize;

		float m_threshold;
		float m_constant;

		float m_maxAcceleration;

		Boid * m_targets;

		Boid &m_character;
	};
}
