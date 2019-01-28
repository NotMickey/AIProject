#pragma once

#include "ofMain.h"

namespace AIProject
{
	struct DynamicSteeringOutput;

	struct Kinematic
	{
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

		Kinematic m_kinematic;

		void Update(const double &i_timeStep, const float &i_maxSpeed);
		void Draw();

		ofVec2f GetForwardVec() { return m_forwardVector; }

		void SetTargetPosition(const ofVec2f &i_targetPosition);

		DynamicSteeringOutput SeekAndSteer(const int &x, const int &y);

		DynamicSteeringOutput SteerAndArrive(const int &x, const int &y);

		DynamicSteeringOutput Wander();

	private:

		bool b_reachedLimit = false;
		bool b_seekTargetValid = false;

		int m_breadCrumbIndex = 0;
		ofVec2f m_breadCrumbArray[200];

		ofVec2f m_previousPosition;

		ofVec2f m_targetPosition;

		ofVec2f m_forwardVector;
	};
}
