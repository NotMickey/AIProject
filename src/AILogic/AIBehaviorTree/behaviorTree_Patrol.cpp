#include "behaviorTree_Patrol.h"

#include "../../Character/boid.h"
#include "../../Graph/TileMap/tileMap.h"

#include "TypeA/task_ChasePlayer.h"
#include "TypeA/task_PlayerCheck.h"
#include "TypeA/task_SetColor.h"
#include "TypeA/task_PatrolArea.h"

#include "../../DecisionMaking/BehaviorTree/Tick/tick.h"
#include "../../DecisionMaking/BehaviorTree/Task/sequencer.h"
#include "../../DecisionMaking/BehaviorTree/Task/selector.h"
#include "../../DecisionMaking/BehaviorTree/Task/randomDecorator.h"

AIProject::DecisionMaking::BehaviorTree_Patrol::BehaviorTree_Patrol(int i_id, const std::shared_ptr<Blackboard>& i_blackboard,
															const std::shared_ptr<Boid>& i_character, const Graph::TileMap & i_tileMap)
	: BehaviorTree(i_id, i_blackboard), m_pPatrolBoid(i_character), m_tileMap(i_tileMap)
{
	m_pBlackboard->Set(Key::AggroDistance, 120, m_treeId, 0);

	std::vector<int> patrolNodes;
	patrolNodes.push_back(241);
	patrolNodes.push_back(269);

	m_pRoot = new Selector(10);

	std::shared_ptr<Task> sequencer = std::make_shared<Sequencer>(Sequencer(15));

	sequencer->AddChildTask(std::make_shared<Task_PlayerCheck>(Task_PlayerCheck(20, m_pPatrolBoid)));
	sequencer->AddChildTask(std::make_shared<Task_SetColor>(Task_SetColor(25, m_pPatrolBoid)));
	sequencer->AddChildTask(std::make_shared<Task_ChasePlayer>(Task_ChasePlayer(30, m_pPatrolBoid, m_tileMap)));

	m_pRoot->AddChildTask(sequencer);
	m_pRoot->AddChildTask(std::make_shared<Task_SetColor>(Task_SetColor(35, m_pPatrolBoid)));
	m_pRoot->AddChildTask(std::make_shared<Task_PatrolArea>(Task_PatrolArea(40, m_pPatrolBoid, m_tileMap, patrolNodes)));
}
