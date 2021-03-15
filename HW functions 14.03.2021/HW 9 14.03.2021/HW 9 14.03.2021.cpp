#include <iostream>
using namespace std;

int Sum(int num)
{
	int sum = 0;
	for (int i = 1; i <= num; i++)
		sum += i;
	return sum;
}

int main()
{
	cout << "9.\n\n";
	//Написать функцию, вычисляющую сумму целых чисел от 1 до заданного значения.
	setlocale(LC_ALL, "Russian");
	int num;
	cout << "Введите число:"; cin >> num;
	while (num < 1)
	{
		cout << "Введите число больше 1:"; 
		cin >> num;
	}
	cout << "Сумма целых чисел от 1 до " << num << " = " << Sum(num) << endl;
}