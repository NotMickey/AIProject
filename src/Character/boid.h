#pragma once

#include "ofMain.h"

namespace AIProject
{
	class Boid
	{
	public:

		Boid();

		ofVec2f m_position;
		ofVec2f m_forwardVector;

		void Update();
		void Draw();

	private:

		bool b_reachedLimit = false;

		int m_breadCrumbIndex = 0;
		ofVec2f m_breadCrumbArray[100];
		ofVec2f m_previousPosition;
	};
}
