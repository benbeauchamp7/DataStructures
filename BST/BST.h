#ifndef BST_H
#define BST_H

#include <iostream>

template <typename T>
class BST
{
	struct BSTNode
	{
		T* data;
		BSTNode* left;
		BSTNode* right;

		BSTNode(T* data, BSTNode* left, BSTNode* right):
			data(data), left(left), right(right) {}
		~BSTNode() {}
	};

	BSTNode* root;

	BSTNode* insert(T* data, BSTNode* base)
	{
		if (!base)
		{
			base = new BSTNode(data, nullptr, nullptr);
		}
		else if (*data < *base->data)
		{
			base->left = insert(data, base->left);
		}
		else if (*base->data < *data)
		{
			base->right = insert(data, base->right);
		}
		return base;

	}

	void print(std::ostream& os, BSTNode* base)
	{
		if (base)
		{
			print(os, base->left);
			os << *base->data << " ";
			print(os, base->right);
		}
	}

	BSTNode* makeEmpty(BSTNode* base)
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
	BST(): root(nullptr) {}

	~BST()
	{
		root = makeEmpty(root);
	}

	void insert(T* data) { root = insert(data, root); }

	void print(std::ostream& os) { print(os, root); }

	void makeEmpty() { root = makeEmpty(root); }
};










#endif