#include "obstacle.h"

AIProject::Physics::Obstacle::Obstacle() : m_AABB(ofVec2f(), 10.0f), m_Id(-1), m_length(10.0f), m_position(ofVec2f())
{}

AIProject::Physics::Obstacle::Obstacle(const ofVec2f &i_center, const float &i_sideLength) : m_AABB(i_center, i_sideLength),
																						m_length(i_sideLength), m_position(i_center)
{
	m_Id = rand() % 100000;
}

AIProject::Physics::Obstacle::Obstacle(const Obstacle & i_other) : m_AABB(i_other.m_AABB), m_Id(i_other.m_Id)
{}

int AIProject::Physics::Obstacle::GetID() const
{
	return m_Id;
}

AIProject::Physics::AABB AIProject::Physics::Obstacle::GetAABB() const
{
	return m_AABB;
}

void AIProject::Physics::Obstacle::Draw()
{
	ofColor color;
	color.r = 255; color.g = 255, color.b = 0;
	ofSetColor(color);  // Set the drawing color to yellow

	ofDrawRectangle(m_position, m_length, m_length);
}
