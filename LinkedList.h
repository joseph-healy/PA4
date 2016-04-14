#pragma once

using namespace std;

/*Linked list node template class
<T> - must have well defined operations for =, >, and <<
*/
template<class T>
struct Node
{
	T data;
	Node<T>* next;
};

/*Linked list template class
<T> - must have well defined operations for <<, >, and =
*/
template<class T>
class LinkedList
{
public:

	/*default constructor
	PRE: none
	POST: Empty linked list is initiated
	*/
	LinkedList()
	{
		head = current = tail = nullptr;
	}

	/*value constructor
	PRE: <T> is a data type with well defined behaviour for =, and <<, val is a valid value
	POST: a linked list is initiated with a node containing val at the head
	*/
	LinkedList(T val)
	{
		head = new Node<T>;
		head->data = val;
		head->next = nullptr;
	}

	/*destructor
	PRE: none
	POST: all pointers deleted
	*/
	~LinkedList()
	{
		while (head != nullptr)
		{
			removeItem();
		}
	}

	/*size - counts the elements of the list
	PRE: none
	POST: an int is returned that is the number of nodes in the list
	*/
	int size() const
	{
		int ct = 0;
		Node<T>* temp = head;

		while (temp != nullptr)
		{
			ct++;
			temp = temp->next;
		}

		return ct;
	}

	/*addItem - adds an item to the end of the list
	PRE: <T> is a data type with well defined behaviour for =, and <<, val is a valid value
	POST: a node containing val is added onto the end of the list
	*/
	void addItem(T val)
	{
		if (head == nullptr)
		{
			head = new Node<T>{ val, nullptr };
		}
		else
		{
			current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			tail = current->next = new Node<T>;
			tail->next->data = val;
			tail->next->next = nullptr;
		}
	}

	/*queueAddItem - adds an item to the list, as if the list was a queue (FIFO)
	PRE: <T> is a data type with well defined behaviour for =, and <<, val is a valid value
	POST: a node containinig val is added onto the front of the list and set to head
	*/
	void queueAddItem(T val)
	{
		if (head == nullptr)
		{
			head = new Node<T>{ val, nullptr };
		}
		else
		{
			Node<T>* temp = new Node{ val, head };
			head = temp;
		}
	}

	void printQueue()
	{

	}

	/*insertsItem - inserts an item into the list after the given index
	PRE: <T> is a data type with well defined behaviour for =, and <<, val is a valid value, index is a valid index in the list
	POST: a node containing val is inserted into the list after index
	*/
	void insertItem(T val, int index)
	{
		int size = this->size();
		if (index <= size)
		{
			current = head;
			for (int i = 1; i < index; i++) // i starts at one because, the 0 step of the loop was already accomplished in the previous statement
			{
				current = current->next;
			}
			Node<T>* temp = current->next;
			current->next = new Node<T>{ val, temp };
		}
		else
		{
			return;
		}
	}

	/*removeItem - removes the last item from the list
	PRE: none
	POST: the last node pointer in the list is deleted
	*/
	void removeItem()
	{
		if (head == nullptr)
		{
			return;
		}
		if (head->next == nullptr)
		{
			delete head;
			current = head = nullptr;
			return;
		}

		current = head;
		while (current->next->next != nullptr)
		{
			current = current->next;
		}

		delete current->next;
		current->next = nullptr;
	}

	/*removeItemAt - removes a node from a particular spot on the list
	PRE: index is a valid spot on the list
	POST: the node at <index>
	*/
	void removeItemAt(int index)
	{
		int size = this->size();
		if (index == 0) //when the head is deleted
		{
			Node<T>* temp = head->next;
			delete head;
			head = temp;
		}
		if (index <= size)
		{
			current = head;
			for (int i = 1; i < index - 1; i++) // i starts at one because, the 0 step of the loop was already accomplished in the previous statement
			{
				current = current->next;
			}

			if (current->next->next != nullptr)
			{
				Node<T>* temp = current->next->next; // 1 Spot after <index>
				delete current->next;
				current->next = temp;
			}
			else
			{
				delete current->next;
				current->next = nullptr;
			}
		}
		else
		{
			return;
		}
	}

	/*clearList - removes all nodes from the list
	PRE: none
	POST: all node pointers are deleted
	*/
	void clearList()
	{
		while (head != nullptr)
		{
			removeItem();
		}
		head = current = tail = nullptr;
	}

	/*printList - prints a list to standard out
	PRE: none
	POST: the list is displayed on standard out
	*/
	void printList()
	{
		current = head;
		int i = 0;
		while (current != nullptr)
		{
			cout << i << ": " << current->data << endl;
			current = current->next;
			i++;
		}
		cout << "Size: " << size() << endl;
	}

	/*sort() - sorts the list with the bubble sort algorithm
	PRE: none
	POST: the list is sorted in ascending order
	*/
	void sort()
	{
		bool swapped = true;
		while (swapped)
		{
			swapped = false;
			current = head;
			while (current->next != nullptr)
			{
				if (current->data > current->next->data)
				{
					T tmp = current->data;
					current->data = current->next->data;
					current->next->data = tmp;
					swapped = true;
				}
				current = current->next;
			}
		}
	}

private:

	Node<T>* head;
	Node<T>* current;
	Node<T>* tail;

};
