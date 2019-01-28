#pragma once

#include "../../steeringBase.h"
#include "../../../Character/boid.h"

namespace AIProject
{
	class DynamicFace: public SteeringBase
	{
	public:
		DynamicFace(Boid &i_character, const ofVec2f &i_targetPosition, const float &i_maxRotation, const float &i_maxAngAcc,
			const float &i_targetAngle, const float &i_slowAngle, const float &i_timeToTarget);
		//DynamicArrive(const DynamicArrive &i_dynamicArrive);

		DynamicSteeringOutput GetSteering();

	private:
		float m_maxRotation;
		float m_maxAngAcc;
		float m_targetAngle;
		float m_slowAngle;
		float m_timeToTarget;
		ofVec2f m_targetPosition;
		Boid &m_character;
	};
}