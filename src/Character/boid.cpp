#include "boid.h"

AIProject::Boid::Boid()
{
	ofSetCircleResolution(50);

	m_kinematic.position = ofVec2f(150.0f, 100.0f);
	m_previousPosition = m_kinematic.position;

	m_kinematic.orientation = PI / 180 * 0.0f;

	m_forwardVector = ofVec2f(cosf(m_kinematic.orientation), sinf(m_kinematic.orientation));
}

void AIProject::Boid::Update()
{
	m_forwardVector = ofVec2f(m_kinematic.orientation), sinf(m_kinematic.orientation));

	if (m_previousPosition.distance(m_kinematic.position) >= 15.0f)
	{
		m_breadCrumbIndex++;

		if (m_breadCrumbIndex == 100)
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

	if (!b_reachedLimit)
	{
		for (int i = 0; i < m_breadCrumbIndex + 1; i++)
		{
			ofDrawCircle(m_breadCrumbArray[i], 5);
		}
	}
	else
	{
		for (int i = 0; i < 100; i++)
		{
			ofDrawCircle(m_breadCrumbArray[i], 5);
		}
	}
}

