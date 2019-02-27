#include "dynamicPathFollow.h"

#include "../DynamicArrive/dynamicArrive.h"

AIProject::DynamicPathFollow::DynamicPathFollow(Boid & i_character, const float & i_maxSpeed, const float & i_maxAcceleration,
										const float & i_slowRadius, const float & i_targetRadius, const std::vector<ofVec2f>& i_waypoints) :
	m_character(i_character), m_maxSpeed(i_maxSpeed), m_maxAcceleration(i_maxAcceleration), m_slowRadius(i_slowRadius),
	m_targetRadius(i_targetRadius), m_waypoints(i_waypoints)
{}

AIProject::DynamicSteeringOutput AIProject::DynamicPathFollow::GetSteering()
{
	DynamicSteeringOutput output;

	if (!m_waypoints.empty())
	{
		ofVec2f targetPosition = m_waypoints[m_waypoints.size() - 1];

		float distance = m_character.m_kinematic.position.distance(targetPosition);

		if (distance < m_targetRadius)
		{
			m_waypoints.pop_back();

			if (!m_waypoints.empty())
				targetPosition = m_waypoints[m_waypoints.size() - 1];
		}

		Kinematic target;
		target.position = targetPosition;

		DynamicArrive arrive(m_character, target, m_maxAcceleration, m_maxSpeed, m_targetRadius, m_slowRadius, 0.7f);

		output = arrive.GetSteering();
	}

	return output;
}
