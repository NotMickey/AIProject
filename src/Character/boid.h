#pragma once

#include "ofMain.h"

#include "../AILogic/steeringBase.h"

namespace AIProject
{
	struct Kinematic
	{
		int id = 0;

		ofVec2f position;
		float orientation; // in radians!

		ofVec2f velocity;
		float rotation;

		void Update(const DynamicSteeringOutput &i_steering, const double &i_timeStep, const float &i_maxSpeed);
	};

	class Boid
	{
	public:
		Boid();
		Boid(const int &i_mass);

		int m_mass;

		Kinematic m_kinematic;

		DynamicSteeringOutput currentSteering;

		void Update(const double &i_timeStep, const float &i_maxSpeed);
		void Draw();

		ofVec2f GetForwardVec() { return m_forwardVector; }

		void SetTargetPosition(const ofVec2f &i_targetPosition);
		void SetWayPoints(const std::vector<ofVec2f> &i_waypoints);

		DynamicSteeringOutput SeekAndSteer(const int &x, const int &y);

		DynamicSteeringOutput SteerAndArrive(const int &x, const int &y);

		DynamicSteeringOutput Wander();

		DynamicSteeringOutput PathFind();

		~Boid();

	private:

		SteeringBase* m_pPathFollow;

		bool b_reachedLimit = false;
		bool b_seekTargetValid = false;

		int m_breadCrumbIndex = 0;
		ofVec2f m_breadCrumbArray[200];

		ofVec2f m_previousPosition;

		ofVec2f m_targetPosition;

		ofVec2f m_forwardVector;
	};
}
