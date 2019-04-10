#pragma once

#include "Base/boidBase.h"

#include "../AILogic/steeringBase.h"

namespace AIProject
{
	class Boid
	{
	public:
		Boid(const ofVec2f &i_position = ofVec2f());
		Boid(const int &i_mass);

		bool m_bShowPath = false;
		bool m_bWander = false;

		int m_mass;

		Kinematic m_kinematic;

		DynamicSteeringOutput currentSteering;

		void Update(const double &i_timeStep, const float &i_maxSpeed);
		void Draw();

		ofVec2f GetForwardVec() { return m_forwardVector; }

		void SetTargetPosition(const ofVec2f &i_targetPosition);
		void SetWayPoints(const std::vector<ofVec2f> &i_waypoints);

		DynamicSteeringOutput SeekAndSteer(const int &x, const int &y);

		DynamicSteeringOutput SteerAndArrive(const int &x, const int &y);

		DynamicSteeringOutput Wander();

		DynamicSteeringOutput PathFind();

		~Boid();

	private:

		SteeringBase* m_pPathFollow;

		bool m_bReachedLimit = false;
		bool m_bSeekTargetValid = false;

		int m_breadCrumbIndex = 0;
		ofVec2f m_breadCrumbArray[200];

		ofVec2f m_previousPosition;

		ofVec2f m_targetPosition;

		ofVec2f m_forwardVector;
	};
}
