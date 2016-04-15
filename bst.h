#pragma once
#ifndef _BST_H
#define _BST_H

#include <iostream>
#include "Queue.h"

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
	bool dfSearch(Node<T> *node, T &searchkey);
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

/*      Pre:  None
*     Post:  This object is initialized using default values
*  Purpose:  To intialize BST object
*************************************************************************/
template <typename T>
BST<T>::BST()
{
	mRootNode = NULL;
}

/*      Pre:  None
*     Post:  This object is initialized using specified values
*  Purpose:  To intialize BST object
*************************************************************************/
template <typename T>
BST<T>::BST(T data, Node<T> *left = NULL, Node<T> *right = NULL)
{
	Node<T> *newNode;

	newNode = new Node(data, left, right);
	if (newNode != NULL)
		mRootNode = newNode;
}

/*      Pre:  None
*     Post:  This object is destructed, all subtrees and pointers deleted
*  Purpose:  To delete the object without causing memory problems
*************************************************************************/
template <typename T>
BST<T>::~BST()
{
	destroySubtree(mRootNode);
}

/*      Pre:  An initialized binary search tree, and a valid searchkey. <T> must have well defined behaviour for << and ==
*     Post:  a Breadth first traversal of the tree is printed to standard out. Returns true if searchkey is found, otherwise false
*  Purpose:  To perform a Breadth first search
*************************************************************************/
template <typename T>
bool BST<T>::bfs(T searchKey)
{
	Queue<Node<T>*>	q;
	q.addItem(mRootNode);
	cout << mRootNode->mData << ", ";
	while (!(q.isEmpty()))
	{
		Node<T>* temp = q.getFront();
		if (temp->mLeft != NULL)
		{
			q.addItem(temp->mLeft);
			if (temp->mLeft->mData == searchKey)
			{
				cout << temp->mLeft->mData << endl;
				return true;
			}
			else
			{
				cout << temp->mLeft->mData << ", ";
			}
		}

		if (temp->mRight != NULL)
		{
			q.addItem(temp->mRight);
			if (temp->mRight->mData == searchKey)
			{
				cout << temp->mRight->mData << endl;
				return true;
			}
			else
			{
				cout << temp->mRight->mData << ", ";
			}
		}
		q.removeFromFront();
	}
	return false;
}


/*      Pre:  An initialized binary search tree
*     Post:  The number of nodes in the tree are returned
*  Purpose:  To count the nodes in the tree
*************************************************************************/
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

/*      Pre:  An initialized binary search tree
*     Post:  The number of leaves in the tree are returned
*  Purpose:  To count the leaves in the tree
*************************************************************************/
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

/*      Pre:  An initialized binary search tree
*     Post:  The height of the tree is returned (0 indexed)
*  Purpose:  Calculating the height of a binary search tree
*************************************************************************/
template<typename T>
int BST<T>::countHeight(Node<T>* root)
{
	if (root == NULL)
		return 0;
	else
		return (max(countHeight(root->mLeft), countHeight(root->mRight)) + 1);
}

/*      Pre:  two valid integers
*     Post:  the maximum of the two values is returned to the user
*  Purpose:  find the maximum value between two ints, to be used by the countHeight function 
*************************************************************************/
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

/*      Pre:  An initialized binary search tree
*     Post:  The subtree of node is deleted, all pointers are deleted
*  Purpose:  To delete a subtree, or even a whole tree if you want
*************************************************************************/
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

/*      Pre:  An initialized binary search tree, and a valid searchkey. <T> must have well defined behaviour for << and ==
*     Post:  a Depth first traversal of the tree is printed to standard out. Returns true if searchkey is found, otherwise false
*  Purpose:  To perform a Depth first search, wrapper function for the recursive dfSearch function
*************************************************************************/
template <typename T>
bool BST<T>::dfs(T searchKey)
{
	return dfSearch(mRootNode, searchKey);;
}

/*      Pre:  An initialized binary search tree, and a valid searchkey. <T> must have well defined behaviour for << and ==
*     Post:  a Depth first traversal of the tree is printed to standard out. Returns true if searchkey is found, otherwise false
*  Purpose:  To perform a Depth first search, to be used by the dfs function
*************************************************************************/
template <typename T>
bool  BST<T>::dfSearch(Node<T>* node, T &searchkey)
{
	if (node == NULL)
		return false;
	if (node->mData == searchkey)
	{
		cout << node->mData << endl;
		return true;
	}
	else
	{
		cout << node->mData << ",";
		if(dfSearch(node->mLeft, searchkey)) 
			return true;
		if(dfSearch(node->mRight, searchkey)) 
			return true;
	}
}

/*      Pre:  An initialized binary search tree, and a valid searchkey. <T> must have well defined behaviour for << and ==
*     Post:  the tree is displayed on the console using an in-order traversal
*  Purpose:  To show the tree to the user in in-order notation
*************************************************************************/
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

/*      Pre:  An initialized binary search tree, and a valid searchkey. <T> must have well defined behaviour for << and ==
*     Post:  the tree is displayed on the console using a pre-order traversal
*  Purpose:  To show the tree to the user in pre-order notation
*************************************************************************/
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

/*      Pre:  An initialized binary search tree, and a valid searchkey. <T> must have well defined behaviour for << and ==
*     Post:  the tree is displayed on the console using a post-order traversal
*  Purpose:  To show the tree to the user in post-order notation
*************************************************************************/
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

/*      Pre:  An initialized binary search tree, and a valid searchkey. <T> must have well defined behaviour for << and ==
*     Post:  the tree is displayed in heirarchal order
*  Purpose:  To show the tree to the user in heirarchal order
*************************************************************************/
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

/*      Pre:  An initialized binary search tree
*     Post:  The height of the tree is returned (0 indexed)
*  Purpose:  Calculating the height of a binary search tree, wrapper for the countHeight function
*************************************************************************/
template <typename T>
int BST<T>::getHeight()
{
	return countHeight(mRootNode);
}

/*      Pre:  An initialized binary search tree
*     Post:  A node containinf data is inserted into appropriate spot in the tree
*  Purpose:  to insert a value into the tree
*************************************************************************/
template <typename T>
void BST<T>::insert(T data)
{
	insert(mRootNode, data);
}

/*      Pre:  An initialized binary search tree
*     Post:  A node containinf data is inserted into appropriate spot in the tree
*  Purpose:  to insert a value into the tree
*************************************************************************/
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

/*      Pre:  An initialized binary search tree
*     Post:  if thre tree is empty returns true, otherwise false
*  Purpose:  to find out if a tree is empty
*************************************************************************/
template <typename T>
bool BST<T>::isEmpty()
{
	return (mRootNode == NULL);
}

/*      Pre:  An initialized binary search tree, a valid searchkey. <T> must have well defined behaviour for <<, > and ==
*     Post:  if thre tree is empty returns true, otherwise false
*  Purpose:  to find out if a tree is empty
*************************************************************************/
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

/*      Pre:  An initialized binary search tree
*     Post:  The number of leaves in the tree are returned
*  Purpose:  To count the leaves in the tree
*************************************************************************/
template <typename T>
int BST<T>::leavesCount()
{
	return countLeaves(mRootNode);
}

/*      Pre:  An initialized binary search tree
*     Post:  the passed in node is deleted
*  Purpose:  To delete a node from the tree
*************************************************************************/
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

/*      Pre:  An initialized binary search tree
*     Post:  The number of leaves in the tree are returned
*  Purpose:  To count the nodes in the tree
*************************************************************************/
template <typename T>
int BST<T>::nodesCount()
{
	return countNodes(mRootNode);
}

/*      Pre:  An initialized binary search tree
*     Post:  The number of leaves in the tree are returned
*  Purpose:  To count the nodes in the tree
*************************************************************************/
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

/*      Pre:  An initialized binary search tree, and a valid searchkey. <T> must have well defined behaviour for << and ==
*     Post:  the path to the searchkey is printed to standard out
*  Purpose:  To show the path to a particular node in the tree
*************************************************************************/
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

/*      Pre:  An initialized binary search tree
*     Post:  the passed in node is deleted
*  Purpose:  To delete a node from the tree
*************************************************************************/
template <typename T>
void BST<T>::remove(T searchKey)
{
	remove(mRootNode, searchKey);
}

/*      Pre:  An initialized binary search tree, and a valid searchkey. <T> must have well defined behaviour for << and ==
*     Post:  the tree is displayed on the console using an in-order traversal
*  Purpose:  To show the tree to the user in in-order notation
*************************************************************************/
template <typename T>
void BST<T>::showInOrder()
{
	displayInOrder(mRootNode);
}

/*      Pre:  An initialized binary search tree, and a valid searchkey. <T> must have well defined behaviour for << and ==
*     Post:  the tree is displayed on the console using a pre-order traversal
*  Purpose:  To show the tree to the user in pre-order notation
*************************************************************************/
template <typename T>
void BST<T>::showPreOrder()
{
	displayPreOrder(mRootNode);
}

/*      Pre:  An initialized binary search tree, and a valid searchkey. <T> must have well defined behaviour for << and ==
*     Post:  the tree is displayed on the console using a post-order traversal
*  Purpose:  To show the tree to the user in pre-order notation
*************************************************************************/
template <typename T>
void BST<T>::showPostOrder()
{
	displayPostOrder(mRootNode);
}

/*      Pre:  An initialized binary search tree, and a valid searchkey. <T> must have well defined behaviour for << and ==
*     Post:  the tree is displayed in heirarchal order
*  Purpose:  To show the tree to the user in heirarchal order
*************************************************************************/
template <typename T>
void BST<T>::showTree()
{
	displayTree(mRootNode, 0);
}

#endif