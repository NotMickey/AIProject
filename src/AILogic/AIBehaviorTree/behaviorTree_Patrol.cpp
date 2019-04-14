#include "behaviorTree_Patrol.h"

#include "../../Character/boid.h"
#include "../../Graph/TileMap/tileMap.h"

#include "TypeA/task_ChasePlayer.h"
#include "TypeA/task_PlayerCheck.h"

#include "../../DecisionMaking/BehaviorTree/Tick/tick.h"
#include "../../DecisionMaking/BehaviorTree/Task/sequencer.h"


AIProject::DecisionMaking::BehaviorTree_Patrol::BehaviorTree_Patrol(const std::shared_ptr<Boid>& i_character,
													const Graph::TileMap & i_tileMap, const std::shared_ptr<Blackboard>& i_blackboard)
	: m_pPatrolBoid(i_character), m_tileMap(i_tileMap), m_pBlackboard(i_blackboard), m_pRoot(nullptr)
{
	m_pRoot = new Sequencer(100);

	m_pRoot->AddChildTask(std::make_shared<Task_PlayerCheck>(Task_PlayerCheck(25, 250.0f, m_pPatrolBoid)));
	m_pRoot->AddChildTask(std::make_shared<Task_ChasePlayer>(Task_ChasePlayer(30, m_pPatrolBoid, m_tileMap)));
}

std::shared_ptr<AIProject::DecisionMaking::Action> AIProject::DecisionMaking::BehaviorTree_Patrol::GetAction()
{
	if (m_pRoot != nullptr)
	{
		Tick tick(this, m_pBlackboard);

		m_pRoot->Run(tick);

		return m_pBlackboard->GetAction(Key::action, m_pRoot->m_id);
	}

	return std::shared_ptr<Action>();
}

AIProject::DecisionMaking::BehaviorTree_Patrol::~BehaviorTree_Patrol()
{
	if (m_pRoot != nullptr)
		delete m_pRoot;
}
