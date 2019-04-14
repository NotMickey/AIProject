#include "behaviorTree_Patrol.h"

#include "../../Character/boid.h"
#include "../../Graph/TileMap/tileMap.h"

#include "TypeA/task_ChasePlayer.h"
#include "TypeA/task_PlayerCheck.h"

#include "../../DecisionMaking/BehaviorTree/Tick/tick.h"
#include "../../DecisionMaking/BehaviorTree/Task/sequencer.h"

AIProject::DecisionMaking::BehaviorTree_Patrol::BehaviorTree_Patrol(int i_id, const std::shared_ptr<Blackboard>& i_blackboard,
															const std::shared_ptr<Boid>& i_character, const Graph::TileMap & i_tileMap)
	: BehaviorTree(i_id, i_blackboard), m_pPatrolBoid(i_character), m_tileMap(i_tileMap)
{
	m_pRoot = new Sequencer(10);

	m_pRoot->AddChildTask(std::make_shared<Task_PlayerCheck>(Task_PlayerCheck(25, 250.0f, m_pPatrolBoid)));
	m_pRoot->AddChildTask(std::make_shared<Task_ChasePlayer>(Task_ChasePlayer(30, m_pPatrolBoid, m_tileMap)));
}
