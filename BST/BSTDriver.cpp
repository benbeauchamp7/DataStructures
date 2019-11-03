#include "BST.h"

int main(int argc, char** argv)
{
	BST<int> Tree;

	std::cout << "Running" << std::endl;

	Tree.insert(new int(50));
	Tree.insert(new int(25));
	Tree.insert(new int(10));
	Tree.insert(new int(52));
	Tree.insert(new int(59));
	Tree.insert(new int(101));
	Tree.insert(new int(-4));
	Tree.insert(new int(22));

	Tree.print(std::cout);

	Tree.remove(new int(101));
	Tree.print(std::cout);

	std::cout << Tree.find(new int(50));
	
	return 0;
}

