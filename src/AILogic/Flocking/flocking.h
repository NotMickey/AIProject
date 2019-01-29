#pragma once

#include "ofMain.h"

namespace AIProject
{
	class Boid;

	class Flocking
	{
	public:
		void SimulateFlocking(Boid i_boids[], const int &i_size, const float &i_avoidBoidWeight, const float &i_matchLeaderWeight,
								const float &i_moveTowardsCenterWeight);

	private:
		ofVec2f CalculateCenterOfMass(Boid i_boids[], const int &i_size);

		Boid& GetFlockLeader(Boid i_boids[], const int &i_size);
	};
}