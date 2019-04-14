#include "action_LookRandom.h"

#include "../../Dynamic/DynamicFace/dynamicFace.h"

AIProject::DecisionMaking::Action_LookRandom::Action_LookRandom(const std::shared_ptr<Boid>& i_character, const Graph::TileMap & i_tileMap,
														float i_expiryTime, int i_priority, bool i_canInterrupt)
	: Action(i_expiryTime, i_priority, i_canInterrupt), m_pCharacter(i_character), m_tileMap(i_tileMap)
{
	id = 3;

	m_timer = 0.0f;
	SetNewLookPosition();
}

void AIProject::DecisionMaking::Action_LookRandom::Execute()
{
	m_timer += (float)ofGetLastFrameTime();

	if (m_timer > 6.0f)
	{
		m_timer = 0.0f;
		SetNewLookPosition();

		isComplete = true;
	}

	DynamicFace face(*m_pCharacter, m_lookPosition);

	m_pCharacter->SetSteering(face.GetSteering());
}

void AIProject::DecisionMaking::Action_LookRandom::SetNewLookPosition()
{
	float x = (rand() % (int)(m_pCharacter->m_kinematic.position.x + 120 - (m_pCharacter->m_kinematic.position.x - 120))) + (m_pCharacter->m_kinematic.position.x - 120); // Random X pos
	float y = (rand() % (int)(m_pCharacter->m_kinematic.position.y + 120 - (m_pCharacter->m_kinematic.position.y - 120))) + (m_pCharacter->m_kinematic.position.y - 120); // Random Y pos

	m_lookPosition = ofVec2f(x, y);
}
