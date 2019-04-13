#pragma once

#include "../boid.h"
#include "../../AILogic/AIBrain/aiBrain.h"

namespace AIProject
{
	namespace Graph
	{
		class TileMap;
	}

	class DocileBoid : public Boid
	{
	public:
		DocileBoid(const ofVec2f &i_position = ofVec2f(), int i_mass = 1);

		void InitBrain(const std::shared_ptr<Boid> &i_thisBoid, const Graph::TileMap &i_tileMap);

		void virtual Update(float i_timeStep, float i_maxSpeed) override;

		~DocileBoid();

	private:
		AIBrain* m_pBrain;
	};
}