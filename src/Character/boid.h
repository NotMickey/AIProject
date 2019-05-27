#pragma once

#include "Base/boidBase.h"

#include "../AILogic/steeringBase.h"

namespace AIProject
{
	// Ideally this class shouldn't exist and all Boid characters should directly inherit from BoidBase.
	// But, because all dynamic steering behavior expect, as input, an object of type Boid (before there was a Boid base),
	// this class exists as an extra layer.
	// I will slowly remove all the specific Dynamic behavior functions and might get rid of this class entirely in the future

	class Boid : public BoidBase
	{
	public:
		Boid(const ofVec2f &i_position = ofVec2f(), const ofColor &i_color = ofColor(255, 0, 0, 255), int i_mass = 1);

		void Update(float i_timeStep, float i_maxSpeed) override;

		void SetWayPoints(const std::vector<ofVec2f> &i_waypoints);

		void SetSteering(const DynamicSteeringOutput i_steering);

		virtual ~Boid();

		DynamicSteeringOutput currentSteering;

	protected:
		DynamicSteeringOutput PathFind();

	private:

		//bool m_bWander = false;
		//DynamicSteeringOutput SeekAndSteer(const int &x, const int &y);
		//DynamicSteeringOutput SteerAndArrive(const int &x, const int &y);
		//DynamicSteeringOutput Wander();

		SteeringBase* m_pPathFollow;
		bool m_bSeekTargetValid;
	};
}
