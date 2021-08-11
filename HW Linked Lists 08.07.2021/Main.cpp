#include "Headers.h"

int main()
{
	try
	{

		SinglyLinkedList<int> singly_linked_list;

		DoublyLinkedList<int> doubly_linked_list;

		//RemoveSingleItemTest();

		//AddItemTest();

		//singly_linked_list[0] = 10;

		singly_linked_list.AddToFront(50);

		singly_linked_list.AddToBack(10);
		singly_linked_list.AddToBack(20);
		singly_linked_list.AddToBack(30);

		//50 10 20 30
		singly_linked_list.Print();

		SinglyLinkedList<int> sList = singly_linked_list;
		SinglyLinkedList<int> sList2;

		sList2 = singly_linked_list = sList;

		sList2.Print();


		singly_linked_list.AddToFront(40);
		singly_linked_list.AddAt(42, 0);

		singly_linked_list.Print(); //40 50 10  20  30

		singly_linked_list[0] = 0;
		singly_linked_list[2] = 0;
		singly_linked_list[4] = 0;

		singly_linked_list.RemoveAt(0);
		singly_linked_list.Print();
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}

	//для отлова утечек памяти
	return 0;
}