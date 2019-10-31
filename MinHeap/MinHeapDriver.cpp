#include <iostream>
#include "MinHeap.h"

int main(int argc, char** argv)
{
	int* a = new int(50);
	MinHeap<int> heap(a);

	heap.insert(new int(55));
	heap.insert(new int(52));
	heap.insert(new int(70));
	heap.insert(new int(25));

	heap.print(std::cout);
	
	return 0;
}