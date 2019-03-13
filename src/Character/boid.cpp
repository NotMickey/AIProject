#include "boid.h"

#include "../AILogic/steeringBase.h"

#include "../AILogic/Dynamic/DynamicSeek/dynamicSeek.h"
#include "../AILogic/Dynamic/DynamicAlign/dynamicAlign.h"
#include "../AILogic/Dynamic/DynamicArrive/dynamicArrive.h"
#include "../AILogic/Dynamic/DynamicWander/dynamicWander.h"
#include "../AILogic/Dynamic/DynamicPathFollow/dynamicPathFollow.h"
#include "../AILogic/Dynamic/CollisionAvoidance/collisionAvoidance.h"

AIProject::Boid::Boid(const ofVec2f &i_position)
{
	m_mass = 1;

	ofSetCircleResolution(50);

	m_kinematic.position = i_position;
	m_previousPosition = m_kinematic.position;

	m_kinematic.orientation = PI / 180 * 0.0f;

	m_kinematic.velocity = ofVec2f(0.0f, 0.0f);
	m_kinematic.rotation = 0.0f;

	m_forwardVector = ofVec2f(cosf(m_kinematic.orientation), sinf(m_kinematic.orientation));

	m_kinematic.id = rand() % 100000;
}

AIProject::Boid::Boid(const int &i_mass) : m_mass(i_mass)
{
	ofSetCircleResolution(50);

	m_kinematic.position = ofVec2f(512, 384);
	m_previousPosition = m_kinematic.position;

	m_kinematic.orientation = PI / 180 * 0.0f;

	m_kinematic.velocity = ofVec2f(0.0f, 0.0f);
	m_kinematic.rotation = 0.0f;

	m_forwardVector = ofVec2f(cosf(m_kinematic.orientation), sinf(m_kinematic.orientation));

	m_kinematic.id = rand() % 100000;
}

void AIProject::Boid::Update(const double &i_timeStep, const float &i_maxSpeed)
{
	DynamicSteeringOutput steering;

	if (m_bWander)
		steering = Wander();

	if (m_bSeekTargetValid && !m_bWander)
	{
		steering = PathFind();

		// Add other dynamic behavior to the Boid
		steering.linearAcceleration += currentSteering.linearAcceleration;
		steering.angularAcceleration += currentSteering.angularAcceleration;
	}

	//m_kinematic.Update(currentSteering, i_timeStep, i_maxSpeed);
	m_kinematic.Update(steering, i_timeStep, i_maxSpeed);
	
	m_forwardVector = ofVec2f(cosf(m_kinematic.orientation), sinf(m_kinematic.orientation));

	if (m_previousPosition.distance(m_kinematic.position) >= 15.0f)
	{
		m_breadCrumbIndex++;

		if (m_breadCrumbIndex == 200)
		{
			m_breadCrumbIndex = 0;
			m_bReachedLimit = true;
		}

		m_breadCrumbArray[m_breadCrumbIndex] = m_previousPosition;

		m_previousPosition = m_kinematic.position;
	}
}

void AIProject::Boid::Draw()
{
	// Draw the boid using its position and forward vector
	ofDrawCircle(m_kinematic.position.x, m_kinematic.position.y, 10);
	ofDrawTriangle(m_forwardVector * 20.0f + m_kinematic.position, m_forwardVector.getPerpendicular() * 10 + m_kinematic.position,
					m_forwardVector.getPerpendicular() * -10 + m_kinematic.position);


	if (m_bShowPath)
	{
		// Draw the bread crumbs
		if (!m_bReachedLimit)
		{
			for (int i = 0; i < m_breadCrumbIndex + 1; i++)
			{
				ofDrawCircle(m_breadCrumbArray[i], 3);
			}
		}
		else
		{
			for (int i = 0; i < 200; i++)
			{
				ofDrawCircle(m_breadCrumbArray[i], 3);
			}
		}
	}
}

void AIProject::Boid::SetTargetPosition(const ofVec2f & i_targetPosition)
{
	m_targetPosition = i_targetPosition;
	m_bSeekTargetValid = true;
}

void AIProject::Boid::SetWayPoints(const std::vector<ofVec2f>& i_waypoints)
{
	if (m_pPathFollow)
		delete m_pPathFollow;

	m_pPathFollow = new DynamicPathFollow(*this, 80.0f, 300.0f, 80.0f, 5.0f, i_waypoints);

	m_bSeekTargetValid = true;
}

AIProject::DynamicSteeringOutput AIProject::Boid::SeekAndSteer(const int &x, const int &y)
{
	DynamicSteeringOutput steering;

	AIProject::Kinematic kinematic;
	kinematic.position = ofVec2f(x, y);

	ofVec2f direction = (ofVec2f(x, y) - m_kinematic.position).normalize();
	kinematic.orientation = atan2f(direction.y, direction.x);

	AIProject::SteeringBase* seek = new AIProject::DynamicSeek(*this, kinematic, 50.0f);
	AIProject::SteeringBase* align = new AIProject::DynamicAlign(*this, kinematic, PI / 180 * 75, PI / 180 * 90, PI / 180 * 2, PI / 180 * 5, 2.0f);

	AIProject::DynamicSteeringOutput linear = seek->GetSteering();
	AIProject::DynamicSteeringOutput angular = align->GetSteering();

	steering.linearAcceleration = linear.linearAcceleration;
	steering.angularAcceleration = angular.angularAcceleration;

	delete align;
	delete seek;

	return steering;
}

AIProject::DynamicSteeringOutput AIProject::Boid::SteerAndArrive(const int & x, const int & y)
{
	DynamicSteeringOutput steering;

	AIProject::Kinematic kinematic;
	kinematic.position = ofVec2f(x, y);

	ofVec2f direction = (ofVec2f(x, y) - m_kinematic.position).normalize();
	kinematic.orientation = atan2f(direction.y, direction.x);

	AIProject::SteeringBase* arrive = new AIProject::DynamicArrive(*this, kinematic, 300.0f, 80.0f, 5.0f, 100.0f, 0.1f);
	AIProject::SteeringBase* align = new AIProject::DynamicAlign(*this, kinematic, PI / 180 * 90, PI / 180 * 200, PI / 180 * 5, PI / 180 * 25, 0.5f);

	AIProject::DynamicSteeringOutput linear = arrive->GetSteering();
	AIProject::DynamicSteeringOutput angular = align->GetSteering();

	steering.linearAcceleration = linear.linearAcceleration;
	steering.angularAcceleration = angular.angularAcceleration;

	delete align;
	delete arrive;

	return steering;
}

AIProject::DynamicSteeringOutput AIProject::Boid::Wander()
{
	DynamicWander wander(*this, 3.0f, 10.0f, 120.0f, 5.0f);

	return wander.GetSteering();
	/*return wander.GetSteeringAlt();*/
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
		delete m_pPathFollow;
}

void AIProject::Kinematic::Update(const DynamicSteeringOutput & i_steering, const double & i_timeStep, const float & i_maxSpeed)
{
	position += velocity * i_timeStep + 0.5f * i_steering.linearAcceleration * i_timeStep * i_timeStep;

	orientation += rotation * i_timeStep + 0.5f * i_steering.angularAcceleration * i_timeStep * i_timeStep;

	velocity += i_steering.linearAcceleration * i_timeStep;
	rotation += i_steering.angularAcceleration * i_timeStep;

	if (velocity.lengthSquared() > i_maxSpeed * i_maxSpeed)
	{
		velocity.normalize();
		velocity *= i_maxSpeed;
	}
}
