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

	BSTNode* getMax(BSTNode* base)
	{
		BSTNode* curr = base;
		for ( ; curr->right; curr = curr->right) {}
		return curr;
	}

	BSTNode* getMin(BSTNode* base)
	{
		BSTNode* curr = base;
		for ( ; curr->left; curr = curr->left) {}
		return curr;
	}

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

	BSTNode* remove(T* data, BSTNode* base)
	{
		BSTNode* curr = base;
		if (*data < *base->data)
		{
			base->left = remove(data, base->left);
		}
		else if (*base->data < *data)
		{
			base->right = remove(data, base->right);
		}
		else if (base->right && base->left)
		{
			base->data = getMin(base->right)->data;
			base->right = remove(data, base->right);
		}
		else
		{
			if (base->right == nullptr)
			{
				base = base->left;
			}
			else if (base->left == nullptr)
			{
				base = base->right;
			}
			delete curr;
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

	BSTNode* find(T* data, BSTNode* base)
	{
		if (base)
		{
			if (*data < *base->data)
			{
				return find(data, base->left);
			}
			else if (*base->data < *data)
			{
				return find(data, base->right);
			}
			else
			{
				return base;
			}
		}
		return nullptr;
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

	T* getMax() { return getMax(root)->data; }

	T* getMin() { return getMin(root)->data; }

	void remove(T* data) { root = remove(data, root); }

	void print(std::ostream& os) { print(os, root); }

	T* find(T* data) { return find(data, root)->data; }

	void makeEmpty() { root = makeEmpty(root); }
};










#endif