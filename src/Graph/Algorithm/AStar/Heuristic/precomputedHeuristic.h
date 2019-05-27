#pragma once

#include "heuristic.h"

namespace AIProject
{
	namespace Graph
	{
		class PrecomputedHeuristic : public Heuristic
		{
		public:
			PrecomputedHeuristic();

			int Estimate(const int& i_currentNode) const override;

		private:
			int m_heuristicArray[18];
		};
	}
}