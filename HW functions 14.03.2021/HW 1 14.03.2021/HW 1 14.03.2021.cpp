#include <iostream>
using namespace std;

int Cube(int num)
{
	return num * num * num;
}

int main()
{
	cout << "1.\n\n";

	//Написать функцию, вычисляющую куб целого числа.

	setlocale(LC_ALL, "Russian");

	int num;
	cout << "Введите число для возведения в куб:"; cin >> num;
	cout << Cube(num) << endl;
}