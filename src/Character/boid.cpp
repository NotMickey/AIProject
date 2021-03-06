#include "boid.h"

#include "../AILogic/Dynamic/DynamicSeek/dynamicSeek.h"
#include "../AILogic/Dynamic/DynamicAlign/dynamicAlign.h"
#include "../AILogic/Dynamic/DynamicArrive/dynamicArrive.h"
#include "../AILogic/Dynamic/DynamicWander/dynamicWander.h"
#include "../AILogic/Dynamic/DynamicPathFollow/dynamicPathFollow.h"
#include "../AILogic/Dynamic/CollisionAvoidance/collisionAvoidance.h"

AIProject::Boid::Boid(const ofVec2f &i_position, const ofColor &i_color, int i_mass)
	: BoidBase(i_position, i_color, i_mass), m_pPathFollow(nullptr), m_bSeekTargetValid(false) {}

void AIProject::Boid::Update(float i_timeStep, float i_maxSpeed)
{
	DynamicSteeringOutput steering;

	//if (m_bWander)
	//	steering = Wander();

	if (m_bSeekTargetValid /*&& !m_bWander*/)
	{
		steering = PathFind();
	}

	// Add other dynamic behavior to the Boid
	steering.linearAcceleration += currentSteering.linearAcceleration;
	steering.angularAcceleration += currentSteering.angularAcceleration;

	currentSteering.linearAcceleration = ofVec2f(0.0f, 0.0f);
	currentSteering.angularAcceleration = 0.0f;

	m_kinematic.Update(steering, i_timeStep, i_maxSpeed);
	
	BoidBase::Update(i_timeStep, i_maxSpeed);
}

void AIProject::Boid::SetWayPoints(const std::vector<ofVec2f>& i_waypoints)
{
	if (m_pPathFollow)
	{
		delete m_pPathFollow;
		m_pPathFollow = nullptr;
	}
		

	m_pPathFollow = new DynamicPathFollow(*this, 80.0f, 300.0f, 80.0f, 5.0f, i_waypoints);

	m_bSeekTargetValid = true;
}

void AIProject::Boid::SetSteering(const DynamicSteeringOutput i_steering)
{
	currentSteering.linearAcceleration = i_steering.linearAcceleration;
	currentSteering.angularAcceleration = i_steering.angularAcceleration;
}

AIProject::DynamicSteeringOutput AIProject::Boid::PathFind()
{
	DynamicSteeringOutput steering;

	steering = m_pPathFollow->GetSteering();

	return steering;
}

AIProject::Boid::~Boid()
{
	if (m_pPathFollow)
	{
		delete m_pPathFollow;
		m_pPathFollow = nullptr;
	}
}

// Steer, Seek and Wander functions (THESE ARE DISABLED FOR NOW)

//AIProject::DynamicSteeringOutput AIProject::Boid::SeekAndSteer(const int &x, const int &y)
//{
//	DynamicSteeringOutput steering;
//
//	AIProject::Kinematic kinematic;
//	kinematic.position = ofVec2f(x, y);
//
//	ofVec2f direction = (ofVec2f(x, y) - m_kinematic.position).normalize();
//	kinematic.orientation = atan2f(direction.y, direction.x);
//
//	AIProject::SteeringBase* seek = new AIProject::DynamicSeek(*this, kinematic, 50.0f);
//	AIProject::SteeringBase* align = new AIProject::DynamicAlign(*this, kinematic, PI / 180 * 75, PI / 180 * 90, PI / 180 * 2, PI / 180 * 5, 2.0f);
//
//	AIProject::DynamicSteeringOutput linear = seek->GetSteering();
//	AIProject::DynamicSteeringOutput angular = align->GetSteering();
//
//	steering.linearAcceleration = linear.linearAcceleration;
//	steering.angularAcceleration = angular.angularAcceleration;
//
//	delete align;
//	delete seek;
//
//	return steering;
//}
//
//AIProject::DynamicSteeringOutput AIProject::Boid::SteerAndArrive(const int & x, const int & y)
//{
//	DynamicSteeringOutput steering;
//
//	AIProject::Kinematic kinematic;
//	kinematic.position = ofVec2f(x, y);
//
//	ofVec2f direction = (ofVec2f(x, y) - m_kinematic.position).normalize();
//	kinematic.orientation = atan2f(direction.y, direction.x);
//
//	AIProject::SteeringBase* arrive = new AIProject::DynamicArrive(*this, kinematic, 300.0f, 80.0f, 5.0f, 100.0f, 0.1f);
//	AIProject::SteeringBase* align = new AIProject::DynamicAlign(*this, kinematic, PI / 180 * 90, PI / 180 * 200, PI / 180 * 5, PI / 180 * 25, 0.5f);
//
//	AIProject::DynamicSteeringOutput linear = arrive->GetSteering();
//	AIProject::DynamicSteeringOutput angular = align->GetSteering();
//
//	steering.linearAcceleration = linear.linearAcceleration;
//	steering.angularAcceleration = angular.angularAcceleration;
//
//	delete align;
//	delete arrive;
//
//	return steering;
//}
//
//AIProject::DynamicSteeringOutput AIProject::Boid::Wander()
//{
//	DynamicWander wander(*this, 3.0f, 10.0f, 120.0f, 5.0f);
//
//	return wander.GetSteering();
//	/*return wander.GetSteeringAlt();*/
//}