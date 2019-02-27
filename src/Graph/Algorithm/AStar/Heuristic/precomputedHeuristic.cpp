#include "precomputedHeuristic.h"

AIProject::Graph::PrecomputedHeuristic::PrecomputedHeuristic()
{
	m_heuristicArray[0] = 145;
	m_heuristicArray[1] = 235;
	m_heuristicArray[2] = 225;
	m_heuristicArray[3] = 115;
	m_heuristicArray[4] = 95;
	m_heuristicArray[5] = 190;
	m_heuristicArray[6] = 100000000;
	m_heuristicArray[7] = 60;
	m_heuristicArray[8] = 55;
	m_heuristicArray[9] = 10;
	m_heuristicArray[10] = 0;
	m_heuristicArray[11] = 70;
	m_heuristicArray[12] = 115;
	m_heuristicArray[13] = 165;
	m_heuristicArray[14] = 175;
	m_heuristicArray[15] = 100000000;
	m_heuristicArray[16] = 100000000;
	m_heuristicArray[17] = 100000000;
}

int AIProject::Graph::PrecomputedHeuristic::Estimate(const int & i_currentNode) const
{
	return m_heuristicArray[i_currentNode];	
}
