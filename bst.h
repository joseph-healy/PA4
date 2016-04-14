#pragma once
#ifndef _BST_H
#define _BST_H

#include <iostream>

using namespace std;

template <typename T>
class BST
{
private:
	template <typename R>
	struct Node
	{
		R       mData;
		Node<R> *mLeft, *mRight;

		/*      Pre:  None
		*     Post:  This object is initialized using default values
		*  Purpose:  To intialize date object
		*************************************************************************/
		Node()
		{
			mData = R();
			mLeft = NULL;
			mRight = NULL;
		}

		/*      Pre:  None
		*     Post:  This object is initialized using specified data
		*  Purpose:  To intialize date object
		*************************************************************************/
		Node(R data)
		{
			mData = data;
			mLeft = NULL;
			mRight = NULL;
		}

		/*      Pre:  None
		*     Post:  This object is initialized using specified data with the
		*            specified children attached
		*  Purpose:  To intialize date object
		*************************************************************************/
		Node(R data, Node<R> *left, Node<R> *right)
		{
			mData = data;
			mLeft = left;
			mRight = right;
		}
	};

	Node<T> *mRootNode;

	BST(T data, Node<T> *left, Node<T> *right);


	int countNodes(Node<T> *root); //recursive function to count the nodes in a tree/subtree, to be used in nodesCount() function
	int countLeaves(Node<T> *root); // recursive definition to count the leaves of a tree//subtree
	int countHeight(Node<T> *root); //recursively count the height of a tree or subtree
	int max(int x, int y);
	void destroySubtree(Node<T> *node);
	void displayInOrder(Node<T> *node);
	void displayPreOrder(Node<T> *node);
	void displayPostOrder(Node<T> *node);
	void displayTree(Node<T> *node, int tab);
	void insert(Node<T> *&node, const T &data);
	void makeDeletion(Node<T> *&node);
	void remove(Node<T> *&node, const T &searchKey);

public:
	BST();
	~BST();

	bool bfs(T searchKey);
	bool dfs(T searchKey);
	int  getHeight();
	void insert(T data);
	bool isEmpty();
	bool isExists(T searchKey);
	int  leavesCount();
	int  nodesCount();
	void remove(T searchKey);
	void printPath(T searchKey);
	void showInOrder();
	void showPreOrder();
	void showPostOrder();
	void showTree();
};


template <typename T>
BST<T>::BST()
{
	mRootNode = NULL;
}


template <typename T>
BST<T>::BST(T data, Node<T> *left = NULL, Node<T> *right = NULL)
{
	Node<T> *newNode;

	newNode = new Node(data, left, right);
	if (newNode != NULL)
		mRootNode = newNode;
}


template <typename T>
BST<T>::~BST()
{
	destroySubtree(mRootNode);
}


template <typename T>
bool BST<T>::bfs(T searchKey)
{

	return false;
}


template<typename T>
int BST<T>::countNodes(Node<T>* root)
{
	if (root == NULL) //base case, root is null
		return 0;
	else if (root->mLeft == NULL && root->mRight == NULL) //second base case, root has no children
		return 1;
	else
		return 1 + countNodes(root->mLeft) + countNodes(root->mRight);
}

template<typename T>
int BST<T>::countLeaves(Node<T>* root)
{
	if (root == NULL)
		return 0;
	else if (root->mLeft == NULL && root->mRight == NULL)
		return 1;
	else
		return countLeaves(root->mLeft) + countLeaves(root->mRight);
}

template<typename T>
int BST<T>::countHeight(Node<T>* root)
{
	if (root == NULL)
		return 0;
	else
		return (max(countHeight(root->mLeft), countHeight(root->mRight)) + 1);
}

template<typename T>
int BST<T>::max(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	else
		return y;
}

template <typename T>
void BST<T>::destroySubtree(Node<T> *node)
{
	if (node == NULL)
		return;

	destroySubtree(node->mLeft);
	destroySubtree(node->mRight);

	// Delete the node at the root.
	delete node;
}


template <typename T>
bool BST<T>::dfs(T searchKey)
{
	return false;
}


template <typename T>
void BST<T>::displayInOrder(Node<T> *node)
{
	if (node != NULL)
	{
		displayInOrder(node->mLeft);
		cout << node->mData << "  ";
		displayInOrder(node->mRight);
	}
}


template <typename T>
void BST<T>::displayPreOrder(Node<T> *node)
{
	if (node != NULL)
	{
		cout << node->mData << "  ";
		displayPreOrder(node->mLeft);
		displayPreOrder(node->mRight);
	}
}


template <typename T>
void BST<T>::displayPostOrder(Node<T> *node)
{
	if (node != NULL)
	{
		displayPostOrder(node->mLeft);
		displayPostOrder(node->mRight);
		cout << node->mData << "  ";
	}
}


template <typename T>
void BST<T>::displayTree(Node<T> *node, int tab)
{
	int i;

	if (node != NULL)
	{
		for (i = 0; i < tab; i++)
			cout << "  ";

		cout << node->mData << endl;

		displayTree(node->mLeft, tab + 1);
		displayTree(node->mRight, tab + 1);

	}
}


template <typename T>
int BST<T>::getHeight()
{
	return countHeight(mRootNode);
}


template <typename T>
void BST<T>::insert(T data)
{
	insert(mRootNode, data);
}


template <typename T>
void BST<T>::insert(Node<T> *&node, const T &data)
{
	// If the tree is empty, make a new node and make it 
	// the root of the tree.
	if (node == NULL)
	{
		node = new Node<T>(data);
		return;
	}

	// If num is already in tree: return.
	if (node->mData == data)
		return;

	// The tree is not empty: insert the new node into the
	// left or right subtree.
	if (data < node->mData)
		insert(node->mLeft, data);
	else
		insert(node->mRight, data);
}


template <typename T>
bool BST<T>::isEmpty()
{
	return (mRootNode == NULL);
}


template <typename T>
bool BST<T>::isExists(T searchKey)
{
	Node<T> *tmp = mRootNode;

	while (tmp != NULL)
	{
		if (tmp->mData == searchKey)
			return true;
		else if (tmp->mData > searchKey)
			tmp = tmp->mLeft;
		else
			tmp = tmp->mRight;
	}
	return false;
}


template <typename T>
int BST<T>::leavesCount()
{
	return countLeaves(mRootNode);
}

template <typename T>
void BST<T>::makeDeletion(Node<T> *&node)
{
	// Used to hold node that will be deleted.
	Node<T> *nodeToDelete = node;

	// Used to locate the  point where the 
	// left subtree is attached.
	Node<T> *attachPoint;

	if (node->mRight == NULL)
	{
		// Replace tree with its left subtree. 
		node = node->mLeft;
	}
	else if (node->mLeft == NULL)
	{
		// Replace tree with its right subtree.
		node = node->mRight;
	}
	else
		//The node has two children
	{
		// Move to right subtree.
		attachPoint = node->mRight;

		// Locate the smallest node in the right subtree
		// by moving as far to the left as possible.
		while (attachPoint->mLeft != NULL)
			attachPoint = attachPoint->mLeft;

		// Attach the left subtree of the original tree
		// as the left subtree of the smallest node 
		// in the right subtree.
		attachPoint->mLeft = node->mLeft;

		// Replace the original tree with its right subtree.
		node = node->mRight;
	}

	// Delete root of original tree
	delete nodeToDelete;
}


template <typename T>
int BST<T>::nodesCount()
{
	return countNodes(mRootNode);
}


template <typename T>
void BST<T>::printPath(T searchKey)
{
	Node<T>* temp = mRootNode;

	while (temp->mData != searchKey)
	{
		if (temp != NULL)
		{
			cout << temp->mData << ", ";

			if (temp->mData > searchKey)
			{
				temp = temp->mLeft;
			}
			else
				temp = temp->mRight;
		}
		else
		{
			cout << "Error not found" << endl;
			break;
			return;
		}
	}
	cout << temp->mData;
}

template <typename T>
void BST<T>::remove(Node<T> *&node, const T &searchKey)
{
	if (node == NULL)
		return;
	else if (node->mData > searchKey)
		remove(node->mLeft, searchKey);
	else if (node->mData < searchKey)
		remove(node->mRight, searchKey);
	else
		// We have found the node to delete.
		makeDeletion(node);
}


template <typename T>
void BST<T>::remove(T searchKey)
{
	remove(mRootNode, searchKey);
}


template <typename T>
void BST<T>::showInOrder()
{
	displayInOrder(mRootNode);
}


template <typename T>
void BST<T>::showPreOrder()
{
	displayPreOrder(mRootNode);
}


template <typename T>
void BST<T>::showPostOrder()
{
	displayPostOrder(mRootNode);
}


template <typename T>
void BST<T>::showTree()
{
	displayTree(mRootNode, 0);
}

#endif