#include "docileBoid.h"

#include "../../AILogic/AIDecisionTree/boidBehaviorDocile.h"
#include "../../Graph/TileMap/tileMap.h"

AIProject::DocileBoid::DocileBoid(const Graph::TileMap &i_tileMap, const ofVec2f & i_position, int i_mass)
	: Boid(i_position, i_mass), m_pBrain(new AIBrain(new DecisionMaking::BoidBehaviorDocile(std::make_shared<Boid>(*this), i_tileMap))) {}

void AIProject::DocileBoid::Update(float i_timeStep, float i_maxSpeed)
{
	m_pBrain->Update(i_timeStep);

	Boid::Update(i_timeStep, i_maxSpeed);
}

AIProject::DocileBoid::~DocileBoid()
{
	if (m_pBrain != nullptr)
		delete m_pBrain;
}
