#include "flocking.h"

#include "../../Character/boid.h"
#include "../steeringBase.h"

#include "../BlendedSteering/blendedSteering.h"

#include "../Dynamic/DynamicSeparation/dynamicSeparation.h"
#include "../Dynamic/DynamicVelocity/dynamicVelocity.h"
#include "../Dynamic/DynamicArrive/dynamicArrive.h"

void AIProject::Flocking::SimulateFlocking(Boid(&i_boids)[], const int & i_size, const float &i_avoidBoidWeight, const float &i_matchLeaderWeight,
								const float &i_moveTowardsCenterWeight)
{
	ofVec2f center = CalculateCenterOfMass(i_boids, i_size);
	Kinematic target;
	target.position = center;

	Boid &leader = GetFlockLeader(i_boids, i_size);

	BehaviourAndWeight avoidBoids;
	avoidBoids.weight = i_avoidBoidWeight;
	BehaviourAndWeight matchLeader;
	matchLeader.weight = i_matchLeaderWeight;
	BehaviourAndWeight moveTowardsCenter;
	moveTowardsCenter.weight = i_moveTowardsCenterWeight;

	BehaviourAndWeight behaviours[3];
	behaviours[0].weight = i_avoidBoidWeight;
	behaviours[1].weight = i_matchLeaderWeight;
	behaviours[2].weight = i_moveTowardsCenterWeight;

	BlendedSteering blendSteering(behaviours, 3, 150.0f, 70.0f);

	for (int i = 0; i < i_size; i++)
	{
		behaviours[0].behaviour = new DynamicSeparation(i_boids[i], i_boids, i_size, 15.0f, 4.0f, 150.0f);
		behaviours[1].behaviour = new DynamicVelocity(i_boids[i], leader.m_kinematic, 150.0f, 1.0f);
		behaviours[2].behaviour = new DynamicArrive(i_boids[i], target, 200.0f, 80.0f, 5.0f, 30.0f, 1.0f);

		
	}
}

ofVec2f AIProject::Flocking::CalculateCenterOfMass(Boid(&i_boids)[], const int & i_size)
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

AIProject::Boid & AIProject::Flocking::GetFlockLeader(Boid(&i_boids)[], const int & i_size)
{
	for (int i = 0; i < i_size; i++)
	{
		if (i_boids[i].m_mass > 1)
			return i_boids[i];
	}

	return Boid(2);
}
