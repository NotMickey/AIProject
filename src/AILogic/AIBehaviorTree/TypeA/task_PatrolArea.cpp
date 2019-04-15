#include "task_PatrolArea.h"

#include "../../../DecisionMaking/BehaviorTree/Tick/tick.h"
#include "../../../DecisionMaking/BehaviorTree/status.h"

AIProject::DecisionMaking::Task_PatrolArea::Task_PatrolArea(int i_id, const std::shared_ptr<Boid>& i_thisBoid, const Graph::TileMap & i_tileMap, const std::vector<int>& i_nodes)
	: Task(i_id), m_pBoid(i_thisBoid), m_tileMap(i_tileMap), m_vPatrolNodes(i_nodes) {}

AIProject::DecisionMaking::Status AIProject::DecisionMaking::Task_PatrolArea::OnExecute(Tick & i_tick)
{
	// Check if player was detected while patrolling
	float aggroDistance = i_tick.m_pBlackboard->GetInt(Key::AggroDistance, i_tick.m_pTree->m_treeId, 0);

	if (m_pBoid->m_kinematic.position.squareDistance(i_tick.m_pBlackboard->GetPlayer()->m_kinematic.position) < (aggroDistance * aggroDistance))
	{
		i_tick.m_pBlackboard->Set(Key::Alerted, true, i_tick.m_pTree->m_treeId, 0);

		return Status::FAILURE;
	}

	return Status();
}
