#include <iostream>
using namespace std;

int Avg(int num1, int num2, int num3)
{
	return (num1 + num2 + num3) / 3;
}

int main()
{
	cout << "4.\n\n";

	//Написать функцию, вычисляющую среднее арифметической трех целых чисел.

	setlocale(LC_ALL, "Russian");

	int num1, num2, num3;
	cout << "Введите 3 числа:\n";
	cin >> num1 >> num2 >> num3;
	cout << "СА = " << Avg(num1, num2, num3) << endl;
}