#pragma once

#include "../../steeringBase.h"
#include "../../../Character/boid.h"

namespace AIProject
{
	class DynamicSeek : public SteeringBase
	{
	public:
		DynamicSeek(Boid &i_boid, const Kinematic &i_target, const float i_maxAcceleration);
		DynamicSeek(const DynamicSeek &i_dynamicSeek);

		DynamicSteeringOutput GetSteering();

	private:
		float m_maxAcceleration;
		Kinematic m_target;
		Boid &m_boid;
	};
}