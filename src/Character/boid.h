#pragma once

#include "ofMain.h"

namespace AIProject
{
	struct KinematicSteeringOutput;

	struct Kinematic
	{
		ofVec2f position;
		float orientation; // in radians!

		ofVec2f velocity;
		float rotation;

		void KinematicUpdate(const KinematicSteeringOutput &i_steering, const double &i_timeStep, const float &i_maxSpeed);
		void DynamicUpdate();
	};

	class Boid
	{
	public:

		Boid();

		Kinematic m_kinematic;

		void Update(const double &i_timeStep);
		void Draw();

	private:

		bool b_reachedLimit = false;

		int m_breadCrumbIndex = 0;
		ofVec2f m_breadCrumbArray[100];
		ofVec2f m_previousPosition;

		ofVec2f m_forwardVector;
	};
}
