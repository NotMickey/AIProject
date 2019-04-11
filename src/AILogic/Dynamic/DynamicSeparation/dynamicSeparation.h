#pragma once

#include "../../steeringBase.h"
#include "../../../Character/boid.h"

namespace AIProject
{
	class DynamicSeparation : public SteeringBase
	{
	public:
		DynamicSeparation(Boid &i_character, const std::vector<Boid> &i_targets, float i_threshold, float i_constant,
			float i_maxAcceleration);

		DynamicSteeringOutput GetSteering() override;
	
	private:

		float m_threshold;
		float m_constant;

		float m_maxAcceleration;

		std::vector<Boid> m_vTargets;

		Boid &m_character;
	};
}
