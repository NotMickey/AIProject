#pragma once

#include "heuristic.h"

namespace AIProject
{
	namespace Graph
	{
		class EulerHeuristic : public Heuristic
		{
		public:
			int Estimate(const int& i_currentNode) const override;

		private:

		};
	}
}