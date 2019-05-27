#include "decision_AvoidEnemy.h"

AIProject::DecisionMaking::Decision_AvoidEnemy::Decision_AvoidEnemy(const std::shared_ptr<Boid>& i_character, const std::vector<std::shared_ptr<Boid>> & i_boids,
														DecisionNodeBase * i_trueNode, DecisionNodeBase * i_falseNode)
	: DecisionNode(i_trueNode, i_falseNode), m_pCharacter(i_character), m_vBoids(i_boids)
{}

inline bool AIProject::DecisionMaking::Decision_AvoidEnemy::IsTrue()
{
	if (m_vBoids.empty())
		return false;

	ofVec2f characterPos = m_pCharacter->m_kinematic.position;

	for (int i = 0; i < m_vBoids.size(); i++)
	{
		if (m_pCharacter->m_kinematic.id == m_vBoids[i]->m_kinematic.id)
			continue;

		ofVec2f boidPos = m_vBoids[i]->m_kinematic.position;

		if (characterPos.squareDistance(boidPos) <= 4900.0f)
			return true;
	}

	return false;
}
