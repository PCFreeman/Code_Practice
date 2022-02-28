#include<iostream>
using namespace std;

struct Node
{
	int key;
	Node* left;
	Node* right;
};

Node* newNode(int c)
{
	Node* node = new Node;
	node->key = c;
	node->left = nullptr;
	node->right = nullptr;
	return node;
}

bool checkleaf(Node* node)
{
	if (node == nullptr)
	{
		return false;
	}
	if (node->left == nullptr && node->right == nullptr)
	{
		return true;
	}
}

int Total(Node* root)
{
	int res = 0;

	if (root != nullptr)
	{
		if (checkleaf(root->left))
		{
			res+=root->left->key;
		}
		else
		{
			res += Total(root->left);
		}
		
		res += Total(root->right);
	}

	return res;
}

void main()
{
	struct Node* root = newNode(20);
	root->left = newNode(9);
	root->right = newNode(49);

	cout << "Sum of left leaves is "
		<< Total(root);
}
