#include <iostream>
#include "MinHeap.h"

int main(int argc, char** argv)
{
	std::cout << "HOWDY" << std::endl;
	int* a = new int(50);
	MinHeap<int> heap(a);

	for (int i = 50; i > -50; i -= 5)
	{
		heap.insert(new int(i));
	}

	heap.print(std::cout);
	std::cout << std::endl;

	heap.delMin();
	
	heap.print(std::cout);
	std::cout << std::endl;
	
	return 0;
}