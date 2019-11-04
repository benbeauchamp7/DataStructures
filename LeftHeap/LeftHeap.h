#ifndef LEFTHEAP_H
#define LEFTHEAP_H

template <typename T>
class LeftHeap
{
	struct LHNode
	{
		T* data;
		LHNode* left;
		LHNode* right;
		int npl;

		LHNode(T* data, LHNode* left, LHNode* right): data(data), left(left), right(right), npl(0) {}
	};

	LHNode* data;

	LHNode* insert(T* data, LHNode* base)
	{
		while (base)
	}

	LHNode* makeEmpty(LHNode* base)
	{
		if (base)
		{
			makeEmpty(base->left);
			makeEmpty(base->right);
			delete base;
			base = nullptr;
		}
		return nullptr;
	}

public:
	LeftHeap(): root(nullptr) {}

	~LeftHeap() { makeEmpty(root); }

	void insert(T* data) { root = insert(data, root); }

	void makeEmpty() { root = makeEmpty(root); }
};


#endif