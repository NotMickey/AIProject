#pragma once

#include "../boid.h"
#include "../../AILogic/AIBrain/aiBrain.h"

namespace AIProject
{
	namespace Graph
	{
		class TileMap;
	}

	namespace DecisionMaking
	{
		class Blackboard;
	}

	class PatrolBoid : public Boid
	{
	public:
		PatrolBoid(const ofVec2f &i_position = ofVec2f(), int i_mass = 1);

		void InitBrain(int i_id, const std::shared_ptr<Boid> &i_thisBoid, const Graph::TileMap &i_tileMap, const std::shared_ptr<DecisionMaking::Blackboard> &i_blackboard);

		void virtual Update(float i_timeStep, float i_maxSpeed) override;

		~PatrolBoid();

	private:
		AIBrain * m_pBrain;
	};
}