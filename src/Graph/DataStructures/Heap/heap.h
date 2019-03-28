#pragma once

#include <vector>

namespace AIProject
{
	namespace Graph
	{
		template <class T>
		class Heap
		{
		public:
			Heap(int i_maxSize = 500);
			Heap(const Heap<T> &i_otherTree);
			Heap(T* i_array, const int &i_elemNum, const int &i_maxSize);
			std::vector<T> Sort(); // Built-in HeapSort Algorithm
			~Heap();

			bool Add(const T &i_item);					 // Add the Item to Heap
			T Remove();									 // Remove and return Item from Heap

			T Peak();									 // Return Item without removing it from Heap
			bool Contains(const T &i_item);				 // Check if Item already exists on the Heap

			T Find(const T &i_item);                     // Return a copy of Item from the heap 

			inline int GetSize();						 // Returns the number of nodes in the Heap

		protected:
			T* m_data;									 // Actual Data array
			int m_currentNum;							 // Current number of elements
			const int MAX_SIZE;							 // The maximum number of elements

			void ShiftUp(const int &i_node);			 // Shift Node up into place
			void ShiftDown(const int &i_node);			 // Shift Node down into place

			inline int ParentOf(const int &i_node);      // Returns Parent location
			inline int LeftChildOf(const int &i_node);   // Returns Left Child location
		};
	}
}