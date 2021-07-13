#include "Tree.h"
#include <string>
using std::string;

int main()
{
	Tree<int, int> tree;
	//Tree<int, int> tree3;

	tree.Add(8, 15);
	tree.Add(3, 3);
	tree.Add(10, 10);
	tree.Add(1, 16);
	tree.Add(6, 2);
	tree.Add(9, 33);
	tree.Add(14, 14);

	tree.Print();

	//Tree<int, int> tree2 = tree;

	//tree3 = tree2 = tree;

	//tree2.Print();

	//tree3.Print();


/*
	tree[1] = "zzzz";

	int minKey = tree.MinKey();
	cout << "Min key: " << minKey << endl;
	cout << "Value for min key: " << tree[minKey] << endl;
	cout << "Value for key = 6: " << tree[6] << endl;	

	tree.Remove(1);
	tree.Print();
	
	tree.Remove(14);
	tree.Print();

	tree.Add(1, "qqqq");
	tree.Print();

	tree.Remove(10);
	tree.Print();

	tree.Remove(8);
	tree.Print();*/

}
