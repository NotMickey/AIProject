#pragma once

#include <memory>

#include "ofMain.h"

namespace AIProject
{
	struct DynamicSteeringOutput;

	struct Kinematic
	{
		int id = 0;

		ofVec2f position;
		float orientation; // in radians!

		ofVec2f velocity;
		float rotation;

		void Update(const DynamicSteeringOutput &i_steering, const double &i_timeStep, const float &i_maxSpeed);
	};

	class BoidBase
	{
	public:
		BoidBase(const ofVec2f &i_position = ofVec2f(), int i_mass = 1);

		virtual void Update();

		void Draw();
		void ShowBoidPath(bool i_isTrue = false);

		ofVec2f GetForwardVec() { return m_forwardVector; }

		virtual ~BoidBase() {}

		// ----------------
		// Member Variables
		// ----------------

	public:
		int m_mass;
		Kinematic m_kinematic;

	protected:
		ofVec2f m_forwardVector;

	private:

		// Variables for drawing the boid
		// ------------------------------

		bool m_bShowPath = false;
		bool m_bReachedLimit = false;
		int m_breadCrumbIndex = 0;
		ofVec2f m_breadCrumbArray[200];
		ofVec2f m_previousPosition;
	};
}