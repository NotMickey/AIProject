#include "checkIfStationary.h"

AIProject::DecisionMaking::CheckIfStationary::CheckIfStationary(const std::shared_ptr<Boid> &i_character, DecisionNodeBase * i_trueNode, DecisionNodeBase * i_falseNode)
	: DecisionNode(i_trueNode, i_falseNode), m_pCharacter(i_character), m_timer(0.0f)
{
	m_savedPosition = m_pCharacter->m_kinematic.position;
}

inline bool AIProject::DecisionMaking::CheckIfStationary::IsTrue()
{	
	if (m_savedPosition.squareDistance(m_pCharacter->m_kinematic.position) < 8.0f)
		m_timer += (float)ofGetLastFrameTime();
	else
	{
		m_timer = 0.0f;
		m_savedPosition = m_pCharacter->m_kinematic.position;
	}

	if (m_timer >= 10.0f)
	{
		m_timer = 0.0f;
		return true;
	}

	return false;
}
