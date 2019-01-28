#pragma once

#include "../../steeringBase.h"
#include "../../../Character/boid.h"

namespace AIProject
{
	class DynamicFace: public SteeringBase
	{
	public:
		DynamicFace(Boid &i_character, const ofVec2f &i_targetPosition);
		//DynamicArrive(const DynamicArrive &i_dynamicArrive);

		DynamicSteeringOutput GetSteering();

	private:
		ofVec2f m_targetPosition;
		Boid &m_character;
	};
}