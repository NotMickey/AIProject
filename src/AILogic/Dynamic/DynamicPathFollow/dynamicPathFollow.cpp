#include "dynamicPathFollow.h"

#include "../DynamicArrive/dynamicArrive.h"
#include "../DynamicAlign/dynamicAlign.h"

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

		Kinematic kinematic;
		kinematic.position = targetPosition;

		ofVec2f direction = (targetPosition - m_character.m_kinematic.position).normalize();
		kinematic.orientation = atan2f(direction.y, direction.x);

		DynamicArrive arrive(m_character, kinematic, m_maxAcceleration, m_maxSpeed, m_targetRadius, m_slowRadius, 0.7f);
		DynamicAlign align(m_character, kinematic, PI / 180 * 90, PI / 180 * 200, PI / 180 * 5, PI / 180 * 25, 0.5f);

		AIProject::DynamicSteeringOutput linear = arrive.GetSteering();
		AIProject::DynamicSteeringOutput angular = align.GetSteering();

		output.linearAcceleration = linear.linearAcceleration;
		output.angularAcceleration = angular.angularAcceleration;
	}
	else
	{
		output.linearAcceleration = ofVec2f();
	}

	return output;
}
