#include <iostream>
using namespace std;

inline int GetMin(int num1, int num2)
{
	return num1 < num2 ? num1 : num2;
}

inline int GetMax(int num1, int num2)
{
	return num1 > num2 ? num1 : num2;
}

int main()
{
	cout << "1.\n\n";

	//Написать встраиваемые функции, которые определяют минимум и максимум двух целых чисел.

	setlocale(LC_ALL, "Russian");

	int num1, num2;

	cout << "Введите 2 числа:\n"; cin >> num1 >> num2;
	cout << endl;

	cout << "Min = " << GetMin(num1, num2) << endl
		 << "Max = " << GetMax(num1, num2) << endl;
}