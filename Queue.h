#pragma once
#ifndef _QUEUE_H
#define _QUEUE_H

#include <iostream>

using namespace std;

template<typename T>
class Queue
{

private: 
	
	template<typename R>
	struct Node
	{
		R mData;
		Node<R> *mNext;
		Node()
		{
			mData = R();
			mNext = NULL;
		}

		Node(R data)
		{
			mData = data;
			mNext = NULL;
		}

		Node(R data, Node<R>* next)
		{
			mData = data;
			mNext = next;
		}
	};

	Node<T>* head;
	Node<T>* current;

public: 
	
	/*default constructor
	PRE: none
	POST: Empty Stack is initiated
	*/
	Queue()
	{
		head = current = NULL;
	}

	/*value constructor
	PRE: <T> is a data type with well defined behaviour for =, and <<, val is a valid value
	POST: a queue is initiated with a node containing val at the head
	*/
	Queue(T val)
	{
		head = current = new Node<T>(val, NULL)
	}

	/*addItem - adds an item to the end of the list
	PRE: <T> is a data type with well defined behaviour for =, and <<, val is a valid value
	POST: a node containing val is added onto the end of the list
	*/
	void addItem(T val)
	{
		if (head == NULL)
		{
			head = current = new Node<T>(val, NULL);
		}
		else
		{
			current = head;
			while (current->mNext != NULL)
			{
				current = current->mNext;
			}

			current->mNext = new Node<T>(val, NULL);
		}

	}

	/*printQueue - prints the queue to standard out
	PRE: T has well defined bahaviour for '<<'
	POST: */
	void printQueue()
	{
		current = head;
		while (current != NULL)
		{
			cout << current->mData << ", ";
			current = current->mNext;
		}

		cout << endl;
	}

};
#endif