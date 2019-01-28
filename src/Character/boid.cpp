#include "boid.h"

#include "../AILogic/steeringBase.h";

#include "../AILogic/Dynamic/DynamicSeek/dynamicSeek.h"
#include "../AILogic/Dynamic/DynamicAlign/dynamicAlign.h"
#include "../AILogic/Dynamic/DynamicArrive/dynamicArrive.h"
#include "../AILogic/Dynamic/DynamicWander/dynamicWander.h"

AIProject::Boid::Boid()
{
	ofSetCircleResolution(50);

	m_kinematic.position = ofVec2f(512, 384);
	m_previousPosition = m_kinematic.position;

	m_kinematic.orientation = PI / 180 * 0.0f;

	m_kinematic.velocity = ofVec2f(0.0f, 0.0f);
	m_kinematic.rotation = 0.0f;

	m_forwardVector = ofVec2f(cosf(m_kinematic.orientation), sinf(m_kinematic.orientation));
}

void AIProject::Boid::Update(const double &i_timeStep, const float &i_maxSpeed)
{
	DynamicSteeringOutput steering;
	steering.angularAcceleration = 0.0f;
	steering.linearAcceleration = ofVec2f(0.0f, 0.0f);

	if (b_seekTargetValid)
	{
		steering = SteerAndArrive(m_targetPosition.x, m_targetPosition.y);
	}

	steering = Wander();

	m_kinematic.Update(steering, i_timeStep, i_maxSpeed);
	
	m_forwardVector = ofVec2f(cosf(m_kinematic.orientation), sinf(m_kinematic.orientation));

	if (m_previousPosition.distance(m_kinematic.position) >= 15.0f)
	{
		m_breadCrumbIndex++;

		if (m_breadCrumbIndex == 200)
		{
			m_breadCrumbIndex = 0;
			b_reachedLimit = true;
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

	// Draw the bread crumbs
	if (!b_reachedLimit)
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

void AIProject::Boid::SetTargetPosition(const ofVec2f & i_targetPosition)
{
	m_targetPosition = i_targetPosition;
	b_seekTargetValid = true;
}

AIProject::DynamicSteeringOutput AIProject::Boid::SeekAndSteer(const int &x, const int &y)
{
	DynamicSteeringOutput steering;

	AIProject::Kinematic kinematic;
	kinematic.position = ofVec2f(x, y);

	ofVec2f direction = (ofVec2f(x, y) - m_kinematic.position).normalize();
	kinematic.orientation = atan2f(direction.y, direction.x);

	AIProject::DynamicSeek seek(*this, kinematic, 50.0f);
	AIProject::DynamicAlign align(*this, kinematic, PI / 180 * 75, PI / 180 * 90, PI / 180 * 2, PI / 180 * 5, 2.0f);

	AIProject::DynamicSteeringOutput linear = seek.GetSteering();
	AIProject::DynamicSteeringOutput angular = align.GetSteering();

	steering.linearAcceleration = linear.linearAcceleration;
	steering.angularAcceleration = angular.angularAcceleration;

	return steering;
}

AIProject::DynamicSteeringOutput AIProject::Boid::SteerAndArrive(const int & x, const int & y)
{
	DynamicSteeringOutput steering;

	AIProject::Kinematic kinematic;
	kinematic.position = ofVec2f(x, y);

	ofVec2f direction = (ofVec2f(x, y) - m_kinematic.position).normalize();
	kinematic.orientation = atan2f(direction.y, direction.x);

	AIProject::DynamicArrive arrive(*this, kinematic, 300.0f, 80.0f, 5.0f, 100.0f, 0.1f);

	AIProject::DynamicAlign align(*this, kinematic, PI / 180 * 90, PI / 180 * 200, PI / 180 * 5, PI / 180 * 25, 0.5f);

	AIProject::DynamicSteeringOutput linear = arrive.GetSteering();
	AIProject::DynamicSteeringOutput angular = align.GetSteering();

	steering.linearAcceleration = linear.linearAcceleration;
	steering.angularAcceleration = angular.angularAcceleration;

	return steering;
}

AIProject::DynamicSteeringOutput AIProject::Boid::Wander()
{
	DynamicWander wander(*this, 3.0f, 10.0f, 120.0f, 5.0f);

	return wander.GetSteering();
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
