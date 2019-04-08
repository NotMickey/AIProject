#include "playerInRange.h"

AIProject::DecisionMaking::PlayerInRange::PlayerInRange(const int &i_id, const float & i_minDist, const Boid & i_thisBoid)
	: Task(i_id), m_minDistance(i_minDist), m_thisBoid(i_thisBoid)
{}

AIProject::DecisionMaking::Status AIProject::DecisionMaking::PlayerInRange::OnExecute(Tick & i_tick)
{
	return Status();
}
