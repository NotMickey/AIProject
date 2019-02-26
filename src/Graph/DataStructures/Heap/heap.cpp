#include "heap.h"
#include "../../Algorithm/AStar/AStarHelper.h"
#include "../../Algorithm/Dijkstra/dijkstraHelper.h"

#include <assert.h>

// NOTE: For the templated class, the elements must have the operators >, =, and < defined. 

// This is necessary because the template class needs to know about its instances
template class AIProject::Graph::Heap<AIProject::Graph::NodeRecord>;
template class AIProject::Graph::Heap<AIProject::Graph::NodeRecordDijkstra>;

template<class T>
inline AIProject::Graph::Heap<T>::Heap(int i_maxSize) : MAX_SIZE(i_maxSize)
{
	m_data = new T[MAX_SIZE];
	m_currentNum = 0;
}

template<class T>
inline AIProject::Graph::Heap<T>::Heap(const Heap<T>& i_otherTree) : MAX_SIZE(i_otherTree.MAX_SIZE), m_currentNum(i_otherTree.m_currentNum)
{
	m_data = new T[MAX_SIZE];

	// Copy the array
	for (int i = 0; i < m_currentNum; i++)
	{
		m_data[i] = i_otherTree.m_data[i];
	}
}

template<class T>
inline AIProject::Graph::Heap<T>::Heap(T * i_array, const int &i_elemNum, const int &i_maxSize) : MAX_SIZE(i_maxSize), m_currentNum(i_elemNum)
{
	m_data = new T[MAX_SIZE];

	//TODO : Organize array into the heap
}

template<class T>
T * AIProject::Graph::Heap<T>::Sort()
{
	// The array to be returned
	T* newArray = new T[m_currentNum];

	for (int i = m_currentNum - 1; i >= 0; --i)
	{
		newArray[i] = Remove();
	}

	return newArray;
}

template<class T>
AIProject::Graph::Heap<T>::~Heap()
{
	if (m_data)
		delete m_data;
}

template<class T>
bool AIProject::Graph::Heap<T>::Add(const T &i_item)
{
	if (m_currentNum >= MAX_SIZE) // reached capacity
		return false;

	m_data[m_currentNum] = i_item;
	ShiftUp(m_currentNum++);

	return true;
}

template<class T>
T AIProject::Graph::Heap<T>::Remove()
{
	assert(m_currentNum > 0);

	T temp = m_data[0];

	m_data[0] = m_data[--m_currentNum];
	ShiftDown(0);

	return temp;
}

template<class T>
T AIProject::Graph::Heap<T>::Peak()
{
	assert(m_currentNum > 0);

	T temp = m_data[0];

	return temp;
}

template<class T>
bool AIProject::Graph::Heap<T>::Contains(const T & i_item)
{
	for (int i = 0; i < m_currentNum; i++)
	{
		if (m_data[i] == i_item)
			return true;
	}

	return false;
}

template<class T>
T AIProject::Graph::Heap<T>::Find(const T & i_item)
{
	for (int i = 0; i < m_currentNum; i++)
	{
		if (m_data[i] == i_item)
			return m_data[i];
	}

	return T();
}

template<class T>
inline int AIProject::Graph::Heap<T>::GetSize()
{
	return m_currentNum;
}

template<class T>
void AIProject::Graph::Heap<T>::ShiftUp(const int &i_node)
{
	int current = i_node;

	// If this is the first node, no need to shift up
	if (current == 0)
		return;

	int	parent = ParentOf(current);
	T item = m_data[current];

	while (current > 0) // while current node is not the root node
	{
		if (m_data[parent] > item)
		{
			m_data[current] = m_data[parent];
			current = parent;
			parent = ParentOf(current);
		}
		else
			break;
	}

	m_data[current] = item;
}

template<class T>
void AIProject::Graph::Heap<T>::ShiftDown(const int &i_node)
{
	int current = i_node,
		child   = LeftChildOf(current);
	T item = m_data[current];

	while (child < m_currentNum)
	{
		if (child < (m_currentNum - 1))
			if (m_data[child] > m_data[child + 1])
				++child;

		if (item > m_data[child])
		{
			// Switch the Current node and the Child node
			m_data[current] = m_data[child];
			current = child;
			child = LeftChildOf(current);
		}
		else
			break;
	}

	m_data[current] = item;
}

template<class T>
inline int AIProject::Graph::Heap<T>::ParentOf(const int &i_node)
{
	if (i_node == 0)
		return 0;

	return (i_node - 1) / 2; // decimals are truncated during integer division to give corret value
}

template<class T>
inline int AIProject::Graph::Heap<T>::LeftChildOf(const int &i_node)
{
	return (i_node * 2) + 1;
}







