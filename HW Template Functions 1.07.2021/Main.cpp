#include <iostream>
#include "Template.h"
using namespace std;

int main()
{
	const size_t size = 5;
	int arr[size];
	double arr2[size];
	char* str;

	InputElements(arr, size);
	//InputElements(arr2, size);
	//cout << endl;

	PrintArr(arr, size);
	cout << endl;

	//PrintArr(arr2, size);
	//cout << endl;

	cout << "Max element:\n";

	PrintElement(GetMax(arr, size));
	cout << endl;

	//PrintElement(GetMax(arr2, size));

	cout << endl << "Min element:" << endl;

	PrintElement(GetMin(arr, size));
	cout << endl;

	//PrintElement(GetMin(arr2, size));
	//cout << endl << endl;

	SortArr(arr, size);
	//SortArr(arr2, size);

	PrintArr(arr, size);
	cout << endl;

	//PrintArr(arr2, size);
	//cout << endl << endl;

	//выводит индекс найденного элемента
	PrintElement(SearchKeyElement(arr, size));
}