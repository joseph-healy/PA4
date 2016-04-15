#pragma once
#ifndef _STACK_H
#define _STACK_H

#include <iostream>

using namespace std;

template <typename T>
class Stack
{
private:
	template<typename R>
	struct Node
	{
		R mData;
		Node<R> *mPrev;
		Node<R> *mNext;


		Node()
		{
			mData = R();
			mPrev = NULL;
			mNext = NULL;
		}

		Node(R data)
		{
			mData = data;
			mPrev = NULL;
			mNext = NULL;
		}

		Node(R data, Node<R>* prev)
		{
			mData = data;
			mPrev = prev;
			mNext = NULL;
		}

		Node(R data, Node<R>* prev, Node<R>* next)
		{
			mData = data;
			mPrev = prev;
			mNext = next;
		}
	};
	Node<T>* head;
	Node<T>* tail;
	Node<T>* current;

public:
	/*default constructor
	PRE: none
	POST: Empty Stack is initiated
	*/
	Stack()
	{
		head = current = tail = NULL;
	}

	/*value constructor
	PRE: <T> is a data type with well defined behaviour for =, and <<, val is a valid value
	POST: a stack is initiated with a node containing val at the head
	*/
	Stack(T val)
	{
		head = current = tail = new Node<T>(val, NULL, NULL);
	}

	/*addItem - adds an item to the end of the stack
	PRE: <T> is a data type with well defined behaviour for =, and <<, val is a valid value
	POST: a node containing val is added onto the end of the stack
	*/
	void addItem(T val)
	{
		if (head == NULL)
		{
			head = current = tail = new Node<T>(val, NULL, NULL);
		}
		else
		{
			current = tail;
			current->mNext = new Node<T>(val, tail, NULL);
			tail = current->mNext;
		}
	}

	/*printStack - prints the stack to standard out, in LIFO order
	PRE: <T> has well defined behaviour for <<
	POST: the stack is printed in order of last in first out to standard out, delimited by commas
	*/
	void printStack()
	{
		cout << endl;
		current = tail;
		while (current->mPrev != NULL)
		{
			cout << current->mData << ", ";
			current = current->mPrev;
		}

		cout << endl;
	}
};

#endif