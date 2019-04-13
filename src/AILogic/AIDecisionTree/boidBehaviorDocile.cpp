#include "boidBehaviorDocile.h"

#include "../../Character/boid.h"
#include "../../Graph/TileMap/tileMap.h"

#include "../../DecisionMaking/DecisionTree/Action/actionNode.h"
#include "DecisionNodes/checkIfStationary.h"
#include "Actions/moveRandom.h"

AIProject::DecisionMaking::BoidBehaviorDocile::BoidBehaviorDocile(const std::shared_ptr<Boid>& i_character, const Graph::TileMap &i_tileMap)
{
	m_pRoot = new CheckIfStationary(i_character, new ActionNode(std::make_shared<MoveRandom>(MoveRandom(i_character, i_tileMap, 10.0f, 1))));
}

std::shared_ptr<AIProject::DecisionMaking::Action> AIProject::DecisionMaking::BoidBehaviorDocile::GetAction()
{
	if (m_pRoot != nullptr)
	{
		ActionNode* actionNode = dynamic_cast<ActionNode*>(m_pRoot->MakeDecision());

		if (actionNode != nullptr)
			return actionNode->GetAction();
	}

	return std::shared_ptr<Action>();
}

AIProject::DecisionMaking::BoidBehaviorDocile::~BoidBehaviorDocile()
{
	if (m_pRoot != nullptr)
		delete m_pRoot;
}
