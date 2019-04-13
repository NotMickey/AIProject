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
		DocileBoid(const Graph::TileMap &i_tileMap, const ofVec2f &i_position = ofVec2f(), int i_mass = 1);

		void Update(float i_timeStep, float i_maxSpeed);

		~DocileBoid();

	private:
		AIBrain* m_pBrain;
	};
}