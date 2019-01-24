#pragma once

#include "../steeringBase.h"
#include "../../Character/boid.h"

namespace AIProject
{
	class KinematicSeek : public SteeringBase
	{
	public:
		KinematicSeek(Boid &i_boid, const Kinematic &i_target, const float i_maxSpeed);
		KinematicSeek(const KinematicSeek &i_kinematicSeek);

		KinematicSteeringOutput GetSteering();

	private:
		float m_maxSpeed;
		Kinematic m_target;
		Boid &m_boid;
	};
}