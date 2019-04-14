#include "decision_EdgeCheck.h"

AIProject::DecisionMaking::Decision_EdgeCheck::Decision_EdgeCheck(const std::shared_ptr<Boid>& i_character,
																DecisionNodeBase * i_trueNode, DecisionNodeBase * i_falseNode)
	: DecisionNode(i_trueNode, i_falseNode), m_pCharacter(i_character)
{}

inline bool AIProject::DecisionMaking::Decision_EdgeCheck::IsTrue()
{
	ofVec2f position = m_pCharacter->m_kinematic.position;

	int x = ofGetWidth();
	int y = ofGetHeight();

	if (position.x < 90.0f || position.y < 90.0f)
		return true;

	if (position.x > x - 90.0f || position.y > y - 90.0f)
		return true;

	return false;
}
