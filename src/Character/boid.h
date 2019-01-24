#pragma once

#include "ofMain.h"

namespace AIProject
{
	struct Kinematic
	{
		ofVec2f position;
		float orientation; // in radians!

		ofVec2f velocity;
		float rotation;

		//void Update();
	};

	class Boid
	{
	public:

		Boid();

		Kinematic m_kinematic;

		void Update();
		void Draw();

	private:

		bool b_reachedLimit = false;

		int m_breadCrumbIndex = 0;
		ofVec2f m_breadCrumbArray[100];
		ofVec2f m_previousPosition;

		ofVec2f m_forwardVector;
	};
}
