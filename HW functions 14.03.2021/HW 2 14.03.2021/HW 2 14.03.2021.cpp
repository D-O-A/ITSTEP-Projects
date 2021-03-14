#include <iostream>
using namespace std;

int Min(int num1, int num2)
{
	if (num1 <= num2)
		return num1;
	else
		return num2;
}

int main()
{
	cout << "2.\n\n";

	//Написать функцию, которая находит меньшее из двух целых чисел.

	setlocale(LC_ALL, "Russian");

	int num1, num2;
	cout << "Введите 2 числа:\n";
	cin >> num1 >> num2;
	cout << "Меньшее число = " << Min(num1, num2) << endl;
}