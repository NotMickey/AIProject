#pragma once

#include "../../steeringBase.h"
#include "../../../Character/boid.h"

namespace AIProject
{
	class DynamicLYURG : public SteeringBase
	{
	public:
		DynamicLYURG(Boid &i_character);

		DynamicSteeringOutput GetSteering() override;

	private:
		Boid &m_character;
	};
}