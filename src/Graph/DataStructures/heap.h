#pragma once

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
			T* Sort(); // Built-in HeapSort Algorithm
			~Heap();

			bool Add(const T &i_item);  // Add the Item to Heap
			T Remove();               // Remove and return Item from Heap

			inline int GetSize();     // Returns the number of nodes in the Heap

		protected:
			T* m_data;              // Actual Data array
			int m_currentNum;        // Current number of elements
			const int MAX_SIZE;          // The maximum number of elements

			void ShiftUp(const int &i_node);      // Shift Node up into place
			void ShiftDown(const int &i_node);    // Shift Node down into place

			inline int ParentOf(const int &i_node);      // Returns Parent location
			inline int LeftChildOf(const int &i_node);   // Returns Left Child location
		};
		
	}
}