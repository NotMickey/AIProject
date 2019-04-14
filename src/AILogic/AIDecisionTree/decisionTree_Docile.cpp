#include "decisionTree_Docile.h"

#include "../../Character/boid.h"
#include "../../Graph/TileMap/tileMap.h"

#include "../../DecisionMaking/DecisionTree/Action/actionNode.h"

#include "DecisionNodes/decision_StationaryCheck.h"
#include "DecisionNodes/decision_EdgeCheck.h"

#include "Actions/action_MoveRandom.h"
#include "Actions/action_LookRandom.h"
#include "Actions/action_MoveCenter.h"

AIProject::DecisionMaking::DecisionTree_Docile::DecisionTree_Docile(const std::shared_ptr<Boid>& i_character, const Graph::TileMap &i_tileMap)
{
	m_pRoot = new Decision_EdgeCheck(i_character, 
									  new ActionNode(std::make_shared<Action_MoveCenter>(Action_MoveCenter(i_character, i_tileMap, 2.0f, 9, true))),
									  new Decision_StationaryCheck(i_character,
																	new ActionNode(std::make_shared<Action_MoveRandom>(Action_MoveRandom(i_character, i_tileMap, 4.0f, 5, true))),
																	new ActionNode(std::make_shared<Action_LookRandom>(Action_LookRandom(i_character, i_tileMap, 10.0f, 3, false)))
									  ));

	//m_pRoot = new Decision_StationaryCheck(i_character, new ActionNode(std::make_shared<Action_MoveRandom>(Action_MoveRandom(i_character, i_tileMap, 10.0f, 1))));
}

std::shared_ptr<AIProject::DecisionMaking::Action> AIProject::DecisionMaking::DecisionTree_Docile::GetAction()
{
	if (m_pRoot != nullptr)
	{
		ActionNode* actionNode = dynamic_cast<ActionNode*>(m_pRoot->MakeDecision());

		if (actionNode != nullptr)
			return actionNode->GetAction();
	}

	return std::shared_ptr<Action>();
}

AIProject::DecisionMaking::DecisionTree_Docile::~DecisionTree_Docile()
{
	if (m_pRoot != nullptr)
		delete m_pRoot;
}
