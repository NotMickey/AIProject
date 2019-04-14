#include "behaviorTree_Patrol.h"

#include "../../Character/boid.h"
#include "../../Graph/TileMap/tileMap.h"

#include "../../DecisionMaking/BehaviorTree/Tick/tick.h"
#include "../../DecisionMaking/BehaviorTree/Task/sequencer.h"


AIProject::DecisionMaking::BehaviorTree_Patrol::BehaviorTree_Patrol(const std::shared_ptr<Boid>& i_character,
													const Graph::TileMap & i_tileMap, const std::shared_ptr<Blackboard>& i_blackboard)
	: m_pPatrolBoid(i_character), m_tileMap(i_tileMap), m_pBlackboard(i_blackboard), m_pRoot(nullptr)
{}

std::shared_ptr<AIProject::DecisionMaking::Action> AIProject::DecisionMaking::BehaviorTree_Patrol::GetAction()
{
	if (m_pRoot != nullptr)
	{
		//Tick tick
	}

	return std::shared_ptr<Action>();
}

AIProject::DecisionMaking::BehaviorTree_Patrol::~BehaviorTree_Patrol()
{
	if (m_pRoot != nullptr)
		delete m_pRoot;
}
