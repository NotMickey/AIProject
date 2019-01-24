#pragma once

#include "ofMain.h"

namespace AIProject
{
	constexpr float DEGTORAD = (22 / 7) * (1 / 180);
	constexpr float RADTODEG = (7 / 22) * (180);

	struct Kinematic
	{
		ofVec2f position;
		float orientation; // in degrees

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
