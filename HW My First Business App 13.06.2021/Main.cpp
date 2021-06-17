#include <iostream>
#include <cstring>
#include "Product.h"
#include "ProductStore.h"
using namespace std;

int main()
{
	Product test("Test Name", "Test Description", 0.99, 3);
	
	test.PrintAllObj();

	cout << endl << endl;

	//проверка сеттеров
	test.SetName("Example Name");
	test.SetDescription("Example Description");
	test.SetPrice(39.99);
	test.SetQuantity(42);

	//проверка принтеров
	test.PrintName();
	cout << endl;

	test.PrintDescription();
	cout << endl;

	test.PrintPrice();
	cout << endl;

	test.PrintQuantity();
	cout << endl << endl;

	test.PrintAllObj();
	cout << endl << endl;
	
	//проверка копирования
	Product test2 = test;
	test2.PrintAllObj();

	cout << endl << endl;
	cout << "_______________ProductStore Class Test________________\n\n";

	//проверка класса коллекции
	ProductStore collection(3);

	collection.PrintAllCollection();

	collection.SetCurCollection("1", "1", 1, 1, 1);
	collection.SetCurCollection("2", "2", 2, 2, 2);

	cout << "\n\n\n";

	//проверка копирования
	ProductStore collection2 = collection;
	collection2.PrintAllCollection();

	//вроде даже все корректно работает...?

}