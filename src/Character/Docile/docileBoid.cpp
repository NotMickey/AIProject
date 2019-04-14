#include "docileBoid.h"

#include "../../AILogic/AIDecisionTree/decisionTree_Docile.h"
#include "../../Graph/TileMap/tileMap.h"

AIProject::DocileBoid::DocileBoid(const ofVec2f & i_position, const ofColor &i_color, int i_mass)
	: Boid(i_position, i_color, i_mass), m_pBrain(nullptr) {}

void AIProject::DocileBoid::InitBrain(const std::shared_ptr<Boid> & i_thisBoid, const Graph::TileMap & i_tileMap)
{
	if (m_pBrain != nullptr)
	{
		delete m_pBrain;
		m_pBrain = nullptr;
	}

	m_pBrain = new AIBrain(new DecisionMaking::DecisionTree_Docile(i_thisBoid, i_tileMap));
}

void AIProject::DocileBoid::Update(float i_timeStep, float i_maxSpeed)
{
	m_pBrain->Update(i_timeStep);

	Boid::Update(i_timeStep, i_maxSpeed);
}

AIProject::DocileBoid::~DocileBoid()
{
	if (m_pBrain != nullptr)
	{
		delete m_pBrain;
		m_pBrain = nullptr;
	}
}
