#include "boidBase.h"

#include "../../AILogic/steeringBase.h"

AIProject::BoidBase::BoidBase(const ofVec2f & i_position, int i_mass) : m_mass(i_mass)
{
	ofSetCircleResolution(50);

	m_kinematic.position = i_position;
	m_previousPosition = m_kinematic.position;

	m_kinematic.orientation = PI / 180 * 0.0f;

	m_kinematic.velocity = ofVec2f(0.0f, 0.0f);
	m_kinematic.rotation = 0.0f;

	m_forwardVector = ofVec2f(cosf(m_kinematic.orientation), sinf(m_kinematic.orientation));

	m_kinematic.id = rand() % 100000;
}

void AIProject::BoidBase::Update(float i_timeStep, float i_maxSpeed)
{
	m_forwardVector = ofVec2f(cosf(m_kinematic.orientation), sinf(m_kinematic.orientation));
}

void AIProject::BoidBase::Draw()
{
	// Draw the boid using its position and forward vector
	ofDrawCircle(m_kinematic.position.x, m_kinematic.position.y, 10);
	ofDrawTriangle(m_forwardVector * 20.0f + m_kinematic.position, m_forwardVector.getPerpendicular() * 10 + m_kinematic.position,
		m_forwardVector.getPerpendicular() * -10 + m_kinematic.position);

	if (m_bShowPath)
	{
		// Update breadcrumb index
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

void AIProject::BoidBase::ShowBoidPath(bool i_isTrue)
{
	m_bShowPath = i_isTrue;
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
