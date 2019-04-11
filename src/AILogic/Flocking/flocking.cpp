#include "flocking.h"

#include "../../Character/boid.h"
#include "../steeringBase.h"

#include "../BlendedSteering/blendedSteering.h"

#include "../Dynamic/DynamicSeparation/dynamicSeparation.h"
#include "../Dynamic/DynamicVelocity/dynamicVelocity.h"
#include "../Dynamic/DynamicArrive/dynamicArrive.h"
#include "../Dynamic/dynamicLYURG/dynamicLYURG.h"

void AIProject::Flocking::SimulateFlocking(Boid i_boids[], const int & i_size, const float &i_avoidBoidWeight, const float &i_matchLeaderWeight,
								const float &i_moveTowardsCenterWeight)
{
	ofVec2f center = i_boids[i_size].m_kinematic.position;
	Kinematic target;
	target.position = center;

	Boid &leader = GetFlockLeader(i_boids, i_size);

	BehaviourAndWeight behaviours[4];
	behaviours[0].weight = i_avoidBoidWeight;
	behaviours[1].weight = i_matchLeaderWeight;
	behaviours[2].weight = i_moveTowardsCenterWeight;
	behaviours[3].weight = i_moveTowardsCenterWeight;

	BlendedSteering blendSteering(behaviours, 4, 150.0f, 70.0f);

	for (int i = 0; i < i_size; i++)
	{
		// REPLACED ARRAY WITH VECTOR. WILL FIX THIS LATER!
		//behaviours[0].behaviour = new DynamicSeparation(i_boids[i], i_boids, i_size + 1, 60.0f, 150.0f, 150.0f);
		behaviours[1].behaviour = new DynamicVelocity(i_boids[i], leader.m_kinematic, 60.0f, 1.0f);
		behaviours[2].behaviour = new DynamicArrive(i_boids[i], target, 200.0f, 80.0f, 5.0f, 80.0f, 1.0f);
		behaviours[3].behaviour = new DynamicLYURG(i_boids[i]);

		i_boids[i].currentSteering = blendSteering.GetSteering();

		//delete behaviours[0].behaviour;
		delete behaviours[1].behaviour;
		delete behaviours[2].behaviour;
		delete behaviours[3].behaviour;
	}
}

ofVec2f AIProject::Flocking::CalculateCenterOfMass(Boid i_boids[], const int & i_size)
{
	ofVec2f center(0.0f, 0.0f);

	for (int i = 0; i < i_size; i++)
	{
		center.x += i_boids[i].m_kinematic.position.x * i_boids[i].m_mass;
		center.y += i_boids[i].m_kinematic.position.y * i_boids[i].m_mass;
	}

	center.x /= i_size;
	center.y /= i_size;

	return center;
}

AIProject::Boid & AIProject::Flocking::GetFlockLeader(Boid i_boids[], const int & i_size)
{
	int i = 0;

	for (i = 0; i < i_size + 1; i++)
	{
		if (i_boids[i].m_mass > 1)
			break;
	}

	return i_boids[i];
}
