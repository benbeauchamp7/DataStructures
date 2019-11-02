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
		if (loc > 1 && *data.at(loc) < *data.at(loc / 2))
		{
			// print(std::cout);
			// std::cout << std::endl;
			// std::cout << loc << ": BUBBLING: " << *data.at(loc) << " < " << *data.at(loc/2) << std::endl;
			T* temp = data.at(loc / 2);
			data.at(loc / 2) = data.at(loc);
			data.at(loc) = temp;
			// print(std::cout);
			// std::cout << std::endl;
			// std::cout << std::endl;
			bubbleUp(loc / 2);
		}
	}

	void heapify(int loc)
	{
		if (loc > 0)
		{
			T* temp = data.at(loc);
			if (((2 * loc) < data.size()) && (*data.at(loc) > *data.at(2 * loc)))
			{
				data.at(loc) = data.at(2 * loc);
				data.at(2 * loc) = temp;
				heapify(2 * loc);
			}
			else if (((2 * loc + 1) < data.size()) && (*data.at(loc) > *data.at(2 * loc + 1)))
			{
				data.at(loc) = data.at(2 * loc + 1);
				data.at(2 * loc + 1) = temp;
				heapify(2 * loc + 1);
			}
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
		// std::cout << "--INSERTING: " << *val << std::endl;
		data.insert(data.end(), val);
		bubbleUp(data.size() - 1);
	}

	void delMin()
	{
		if (data.size() > 1)
		{
			std::cout << "--DELETING: " << *data.at(1) << std::endl;
			data.at(1) = data.at(data.size() - 1);
			data.pop_back();
			heapify(1);
		}
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