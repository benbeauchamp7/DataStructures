#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <vector>
#include <iostream>

template <typename T>
class MinHeap
{
	std::vector<T*> data;
	void bubbleUp(int loc)
	{
		if (loc > 1 && *data.at(loc) > *data.at(loc / 2))
		{
			// print(std::cout);
			// std::cout << std::endl;
			// std::cout << loc << ": BUBBLING: " << *data.at(loc) << " > " << *data.at(loc/2) << std::endl;
			T* temp = data.at(loc / 2);
			data.at(loc / 2) = data.at(loc);
			data.at(loc) = temp;
			// print(std::cout);
			// std::cout << std::endl;
			// std::cout << std::endl;
			bubbleUp(loc / 2);
		}
	}

public:
	MinHeap(T* init)
	{
		data = std::vector<T*>();
		data.insert(data.begin(), init);
		data.insert(data.begin(), nullptr);
	}

	~MinHeap()
	{
		while (!data.empty())
		{
			delete data.at(0);
			data.erase(data.begin());
		}
	}

	void insert(T* val)
	{
		data.insert(data.end(), val);
		bubbleUp(data.size() - 1);
	}

	inline int powerOf2(int p)
	{
		int a = 2;
		for (int i = 1; i < p; i++)
		{
			a *= 2;
		}
		return a;
	}

	void print(std::ostream& os)
	{
		int currPower = 1;
		for (int i = 1; i < data.size(); i++)
		{
			if (i == powerOf2(currPower))
			{
				currPower++;
				os << "| ";
			}
			os << *data.at(i) << " ";
		}
	}

};

#endif