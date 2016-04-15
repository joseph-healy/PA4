#include <iostream>
#include "bst.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main()
{
	BST<int> tree;

	cout << "Inserting:  5\n";
	tree.insert(5);

	cout << "Inserting:  8\n";
	tree.insert(8);

	cout << "Inserting:  3\n";
	tree.insert(3);

	cout << "Inserting:  12\n";
	tree.insert(12);

	cout << "Inserting:  9\n";
	tree.insert(9);

	cout << "Inserting:  2\n";
	tree.insert(2);

	cout << "Inserting:  13\n";
	tree.insert(13);

	cout << "Inserting:  0\n";
	tree.insert(0);

	cout << "Inserting:  -1\n";
	tree.insert(-1);

	cout << "Inorder:  ";
	tree.showInOrder();
	cout << endl;

	cout << "Preorder:  ";
	tree.showPreOrder();
	cout << endl;

	cout << "Postorder:  ";
	tree.showPostOrder();
	cout << endl;


	cout << "The tree looks like:\n";
	tree.showTree();

	cout << "Node Count = " << tree.nodesCount() << endl;
	cout << "Leaves Count = " << tree.leavesCount() << endl;
	cout << "Height = " << tree.getHeight() << endl;

	cout << "\n\nDFS:  1\n";
	cout << (tree.dfs(1) ? "Found" : "Not Found") << endl;

	cout << "\n\nDFS:  9\n";
	cout << (tree.dfs(9) ? "Found" : "Not Found") << endl;

	cout << "\n\nBFS:  1\n";
	cout << (tree.bfs(1) ? "Found" : "Not Found") << endl;

	cout << "\n\nBFS:  9\n";
	cout << (tree.bfs(9) ? "Found" : "Not Found") << endl;
	
	system("pause");

	return 0;
}