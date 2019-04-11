#include "moveRandom.h"

#include "../../../Graph/Algorithm/AStar/AStar.h"
#include "../../../Graph/Algorithm/AStar/AStarHelper.h"

#include "../../../Graph/Algorithm/AStar/Heuristic/eulerHeuristic.h"

AIProject::DecisionMaking::MoveRandom::MoveRandom(const std::shared_ptr<Boid>& i_character, const Graph::TileMap & i_tileMap,
											float i_expiryTime, int i_priority, bool i_canInterrupt)
	: Action(i_expiryTime, i_priority, i_canInterrupt), m_pCharacter(i_character), m_tileMap(i_tileMap)
{}

void AIProject::DecisionMaking::MoveRandom::Execute()
{
	// generate waypoints and feed into character : TODO
}
