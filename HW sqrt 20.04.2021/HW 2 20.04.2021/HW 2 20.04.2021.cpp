#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

//#define DEBUG

const int SIZE{ 10 };

void ArrayFill(int arr[])
{
	for (size_t i = 0; i < SIZE; i++)
		arr[i] = rand() % 21 - 10;
}

double AbsAvg(int arr[])
{
	double sum = 0;
	for (size_t i = 0; i < SIZE; i++)
		sum += abs(arr[i]);
	return sum / SIZE;
}

void PrintAvg(double avg)
{
	cout << "СА модулей = " << avg << endl;
}

int main()
{
	cout << "2.\n\n";

	//Написать программу, которая заполняет одномерный массив из десяти целых элементов случайными числами из диапазона [-10, 10] и считает их среднее арифметическое их модулей.

	setlocale(LC_ALL, "Russian");
	srand((unsigned)time(0));

	int arr[SIZE];

	ArrayFill(arr);

#ifdef DEBUG
	for (size_t i = 0; i < SIZE; i++)
		cout << arr[i] << endl;
#endif 

	double avg = AbsAvg(arr);

	PrintAvg(avg);
}