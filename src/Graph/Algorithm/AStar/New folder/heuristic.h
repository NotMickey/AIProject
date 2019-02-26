#pragma once

namespace AIProject
{
	namespace Graph
	{
		class Heuristic
		{
		public:
			virtual ~Heuristic() {};

			virtual int Estimate(const int& i_currentNode) const = 0;

		private:

		};
	}
}