#include <iostream>
using namespace std;

#define CUBE (num) * (num) * (num)
#define AVG ((double)(num1) + (num2)) / 2

//#скорость
inline int __fastcall GetCube(int num)
{
	return CUBE;
}

inline double __fastcall GetAvg(int num1, int num2)
{
	return AVG;
}

int __fastcall GetNum()
{
	int num;
	cout << "Введите число для вычисления куба: "; cin >> num;
	return num;
}

inline void __fastcall PrintCube(int cube)
{
	cout << "Куб числа = " << cube << endl;
}

inline void __fastcall PrintAvg(double avg)
{
	cout << "СА двух чисел = " << avg << endl;
}

int main()
{
	cout << "1.\n\n";

	//Написать макрос для вычисления куба числа.
	//Написать макрос для вычисления среднего арифметического двух чисел.

	setlocale(LC_ALL, "Russian");

	int num = GetNum();
	int cube = GetCube(num);

	PrintCube(cube);

	int num1, num2;

	cout << endl;

	cout << "Введите 2 числа:\n";
	cin >> num1 >> num2;

	double avg = GetAvg(num1, num2);

	PrintAvg(avg);
}