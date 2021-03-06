#include "patrolBoid.h"

#include "../../AILogic/AIBehaviorTree/behaviorTree_Patrol.h"
#include "../../Graph/TileMap/tileMap.h"

AIProject::PatrolBoid::PatrolBoid(const ofVec2f & i_position, const ofColor &i_color, int i_mass)
	: Boid(i_position, i_color, i_mass), m_pBrain(nullptr) {}

void AIProject::PatrolBoid::InitBrain(int i_treeId, const std::shared_ptr<Boid>& i_thisBoid,
								const Graph::TileMap & i_tileMap, const std::shared_ptr<DecisionMaking::Blackboard> &i_blackboard)
{
	m_pBrain = new AIBrain(new DecisionMaking::BehaviorTree_Patrol(i_treeId, i_blackboard, i_thisBoid, i_tileMap));
}

void AIProject::PatrolBoid::Update(float i_timeStep, float i_maxSpeed)
{
	m_pBrain->Update(i_timeStep);

	Boid::Update(i_timeStep, i_maxSpeed);
}

AIProject::PatrolBoid::~PatrolBoid()
{
	if (m_pBrain != nullptr)
	{
		delete m_pBrain;
		m_pBrain = nullptr;
	}
}
