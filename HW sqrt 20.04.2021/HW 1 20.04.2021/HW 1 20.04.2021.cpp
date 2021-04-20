#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cout << "1.\n\n";

	//Написать программу, которая предлагает пользователю ввести параметры квадратного уравнения и вычисляет его корни.

	setlocale(LC_ALL, "Russian");

	double a, b, c, x1, x2;

	//1, -8, 12 - положительный дискриминант
	//5, 3, 7 - отрицательный дискриминант
	//1, -6, 9 - нулевой дискриминант

	cout << "Введите коэффициенты:\n";
	cin >> a >> b >> c;

	double disc = b * b - 4 * a * c;

	cout << "Дискриминант = " << disc << endl;

	if (disc > 0)
	{
		x1 = (-b) + sqrt(disc) / (2 * a);
		x2 = (-b) - sqrt(disc) / (2 * a);
		cout << "2 корня = " << x1 << ", " << x2 << endl;
	}
	else if (!disc)
	{
		x1 = (-b) / (2 * a);
		cout << "Корень =  " << x1;
	}
	else
		cout << "Корней нет.\n";
}