#include "chaseAction.h"

AIProject::DecisionMaking::ChaseAction::ChaseAction(const std::shared_ptr<Boid>& i_character, int i_targetNode, const Graph::TileMap & i_tileMap,
											float i_expiryTime, int i_priority, bool i_canInterrupt)
	: Action(i_expiryTime, i_priority, i_canInterrupt), m_pCharacter(i_character), m_targetNode(i_targetNode), m_tileMap(i_tileMap) {}

void AIProject::DecisionMaking::ChaseAction::Execute()
{

}


