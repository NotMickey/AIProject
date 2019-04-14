#include "decision_StationaryCheck.h"

AIProject::DecisionMaking::Decision_StationaryCheck::Decision_StationaryCheck(const std::shared_ptr<Boid> &i_character, DecisionNodeBase * i_trueNode, DecisionNodeBase * i_falseNode)
	: DecisionNode(i_trueNode, i_falseNode), m_pCharacter(i_character), m_timer(0.0f)
{
	m_savedPosition = m_pCharacter->m_kinematic.position;
}

inline bool AIProject::DecisionMaking::Decision_StationaryCheck::IsTrue()
{	
	if (m_savedPosition.squareDistance(m_pCharacter->m_kinematic.position) < 81.0f)
		m_timer += (float)ofGetLastFrameTime();
	else
	{
		m_timer = 0.0f;
		m_savedPosition = m_pCharacter->m_kinematic.position;
	}

	if (m_timer >= 5.0f)
	{
		m_timer = 0.0f;
		return true;
	}

	return false;
}
