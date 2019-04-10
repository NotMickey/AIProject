#pragma once

#include "Base/boidBase.h"

#include "../AILogic/steeringBase.h"

namespace AIProject
{
	class Boid : public BoidBase
	{
	public:
		Boid(const ofVec2f &i_position = ofVec2f(), int i_mass = 1);

		bool m_bWander = false;

		DynamicSteeringOutput currentSteering;

		void Update(float i_timeStep, float i_maxSpeed) override;

		void SetWayPoints(const std::vector<ofVec2f> &i_waypoints);

		DynamicSteeringOutput SeekAndSteer(const int &x, const int &y);

		DynamicSteeringOutput SteerAndArrive(const int &x, const int &y);

		DynamicSteeringOutput Wander();

		DynamicSteeringOutput PathFind();

		virtual ~Boid();

	private:

		SteeringBase* m_pPathFollow;

		bool m_bSeekTargetValid = false;
	};
}
