#include "boid.h"

AIProject::Boid::Boid()
{
	ofSetCircleResolution(50);

	m_position = ofVec2f(150.0f, 100.f);
	m_forwardVector = ofVec2f(1.0f, 0.0f);

	m_previousPosition = m_position;
}

void AIProject::Boid::Update()
{
	if (m_previousPosition.distance(m_position) >= 15.0f)
	{
		m_breadCrumbIndex++;

		if (m_breadCrumbIndex == 100)
		{
			m_breadCrumbIndex = 0;
			b_reachedLimit = true;
		}

		m_breadCrumbArray[m_breadCrumbIndex] = m_previousPosition;

		m_previousPosition = m_position;
	}
}

void AIProject::Boid::Draw()
{
	ofDrawCircle(m_position.x, m_position.y, 10);
	ofDrawTriangle(m_forwardVector * 20.0f + m_position, m_forwardVector.getPerpendicular() * 10 + m_position,
					m_forwardVector.getPerpendicular() * -10 + m_position);

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
