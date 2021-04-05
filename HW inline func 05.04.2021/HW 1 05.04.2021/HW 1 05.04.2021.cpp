#include <iostream>
using namespace std;

// я не придумал как можно еще проще написать "приемлемую" для компилятора inline функцию 
inline bool IsMin(int num1, int num2)
{
	return num1 > num2;
}

int main()
{
	cout << "1.\n\n";

	//Написать встраиваемые функции, которые определяют минимум и максимум двух целых чисел.

	setlocale(LC_ALL, "Russian");

	int num1, num2;

	cout << "Введите 2 числа:\n"; cin >> num1 >> num2;
	cout << endl;

	cout << "Минимум двух чисел = " << (IsMin(num1, num2) ? num2 : num1) << endl
		 << "Максимум двух чисел = " << (IsMin(num1, num2) ? num1 : num2) << endl;
}