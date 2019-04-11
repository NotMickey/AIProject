#include "checkIfStationary.h"

AIProject::DecisionMaking::CheckIfStationary::CheckIfStationary(const std::shared_ptr<Boid> &i_character, DecisionNodeBase * i_trueNode, DecisionNodeBase * i_falseNode)
	: DecisionNode(i_trueNode, i_falseNode), m_pCharacter(i_character), m_timer(0.0f)
{}

inline bool AIProject::DecisionMaking::CheckIfStationary::IsTrue()
{
	if (m_timer >= 5.0f)
	{
		m_timer = 0.0f;
		return true;
	}
		
	m_timer += (float)ofGetLastFrameTime();

	return false;
}
