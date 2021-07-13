#include "Headers.h"

//void GetFrontAndBackTest()
//{
//    cout << "======= GetFrontAndBackTest ========" << endl;
//    DoublyLinkedList<int> doubly_linked_list;
//
//    try {
//        cout << "head data: " << doubly_linked_list.GetFront() << endl;
//        cout << "tail data: " << doubly_linked_list.GetBack() << endl;
//    }
//    catch (exception& ex) {
//        cout << ex.what() << endl;
//    }
//}
//
//void AddToFrontTest()
//{
//    cout << "======= AddToFront ========" << endl;
//
//    DoublyLinkedList<int> doubly_linked_list;
//    doubly_linked_list.AddToFront(10);
//
//    cout << "size: " << doubly_linked_list.GetSize() << endl;
//    cout << "head data: " << doubly_linked_list.GetFront() << endl;
//    cout << "tail data: " << doubly_linked_list.GetBack() << endl;
//
//    doubly_linked_list.AddToFront(20);
//
//    cout << "size: " << doubly_linked_list.GetSize() << endl;
//    cout << "head data: " << doubly_linked_list.GetFront() << endl;
//    cout << "tail data: " << doubly_linked_list.GetBack() << endl;
//
//    doubly_linked_list.Print();
//    doubly_linked_list.ReversePrint();
//}
//
//void AddToBackTest()
//{
//    cout << "======= AddToBack ========" << endl;
//
//    DoublyLinkedList<int> doubly_linked_list;
//    doubly_linked_list.AddToBack(10);
//
//    cout << "size: " << doubly_linked_list.GetSize() << endl;
//    cout << "head data: " << doubly_linked_list.GetFront() << endl;
//    cout << "tail data: " << doubly_linked_list.GetBack() << endl;
//
//    doubly_linked_list.AddToBack(20);
//
//    cout << "size: " << doubly_linked_list.GetSize() << endl;
//    cout << "head data: " << doubly_linked_list.GetFront() << endl;
//    cout << "tail data: " << doubly_linked_list.GetBack() << endl;
//
//    doubly_linked_list.Print();
//    doubly_linked_list.ReversePrint();
//}
//
//
//void AddItemTest()
//{
//    cout << "======= Add Item ========" << endl;
//    DoublyLinkedList<int> doubly_linked_list;
//
//    doubly_linked_list.AddToFront(42);
//    doubly_linked_list.AddToFront(50);
//    doubly_linked_list.AddToFront(100);
//    doubly_linked_list.AddToBack(1);
//
//    //OG 100, 50, 42, 1
//    doubly_linked_list.AddAt(0, 0);
//
//    cout << "size: " << doubly_linked_list.GetSize() << endl;
//
//    doubly_linked_list.Print();
//    doubly_linked_list.ReversePrint();
//}
//
//void RemoveSingleItemTest()
//{
//    cout << "======= RemoveSingleItem ========" << endl;
//    DoublyLinkedList<int> doubly_linked_list;
//    
//    doubly_linked_list.AddToFront(42);
//    doubly_linked_list.AddToFront(50);
//    doubly_linked_list.AddToFront(100);
//    doubly_linked_list.AddToBack(1);
//
//    doubly_linked_list.RemoveByIndex(0);
//    cout << "size: " << doubly_linked_list.GetSize() << endl;
//
//    //OG 100, 50, 42, 1
//    doubly_linked_list.Print();
//    doubly_linked_list.ReversePrint();
//}
//
//void RemoveFromFrontTest()
//{
//    cout << "======= RemoveFromFront ========" << endl;
//    DoublyLinkedList<int> doubly_linked_list;
//    doubly_linked_list.AddToBack(10);
//    doubly_linked_list.AddToBack(20);
//    doubly_linked_list.AddToBack(30);
//    doubly_linked_list.AddToBack(40);
//
//    doubly_linked_list.RemoveByIndex(0);
//    cout << "size: " << doubly_linked_list.GetSize() << endl;
//    cout << "head data: " << doubly_linked_list.GetFront() << endl;
//
//    doubly_linked_list.Print();
//    doubly_linked_list.ReversePrint();
//}
//
//void RemoveFromBackTest()
//{
//    cout << "======= RemoveFromBack ========" << endl;
//    DoublyLinkedList<int> doubly_linked_list;
//    doubly_linked_list.AddToBack(10);
//    doubly_linked_list.AddToBack(20);
//    doubly_linked_list.AddToBack(30);
//    doubly_linked_list.AddToBack(40);
//
//    doubly_linked_list.RemoveByIndex(3);
//    cout << "size: " << doubly_linked_list.GetSize() << endl;
//    cout << "tail data: " << doubly_linked_list.GetBack() << endl;
//
//    doubly_linked_list.Print();
//    doubly_linked_list.ReversePrint();
//}

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