#include <iostream>
using namespace std;

bool PrimeCheck(int num)
{
	if (num <= 1)
		return false;
	for (int i = 2; i < num; i++)
		if (num % i == 0)
			return false;
	return true;
}

int main()
{
	cout << "13.\n\n";

	//Написать логическую функцию, которая определяет является ли простым заданное число.

	setlocale(LC_ALL, "Russian");

	int num;

	cout << "Введите число:"; cin >> num;

	if (PrimeCheck(num))
		cout << "Это число является простым.\n";
	else
		cout << "Это число не является простым.\n";
}