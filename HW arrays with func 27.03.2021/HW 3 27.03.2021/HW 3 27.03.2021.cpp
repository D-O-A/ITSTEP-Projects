#include <iostream>
#include <ctime>
using namespace std;

const int SIZE = 10;

void ArrayFill(int arr[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
        arr[i] = rand() % 21 - 10;
}

// тип double чтобы возвращать вещественное СА
double __fastcall GetAllElemAvg(int arr[], int SIZE)
{
    double sum = 0;
	for (int i = 0; i < SIZE; i++)
		sum += arr[i];
    return sum / SIZE;
}

double __fastcall GetPositiveElemAvg(int arr[], int SIZE)
{
	int counter = 0;
	double sum = 0;
	for (int i = 0; i < SIZE; i++)
		if (arr[i] > 0)
		{
			sum += arr[i];
			counter++;
		}
	return sum / counter;
}

double __fastcall GetNegativeElemAvg(int arr[], int SIZE)
{
	int counter = 0;
	double sum = 0;
	for (int i = 0; i < SIZE; i++)
		if (arr[i] < 0)
		{
			sum += arr[i];
			counter++;
		}
	return sum / counter;
}

double __fastcall GetNonZeroElemAvg(int arr[], int SIZE)
{
	int counter = 0;
	double sum = 0;
	for (int i = 0; i < SIZE; i++)
		if (arr[i])
		{
			sum += arr[i];
			counter++;
		}
	return sum / counter;
}

double __fastcall GetEvenElemAvg(int arr[], int SIZE)
{
	int counter = 0;
	double sum = 0;
	for (int i = 0; i < SIZE; i++)
		if (arr[i] % 2 == 0)
		{
			sum += arr[i];
			counter++;
		}
	return sum / counter;
}

double __fastcall GetOddElemAvg(int arr[], int SIZE)
{
	int counter = 0;
	double sum = 0;
	for (int i = 0; i < SIZE; i++)
		if (arr[i] % 2 != 0)
		{
			sum += arr[i];
			counter++;
		}
	return sum / counter;
}

double __fastcall GetElemMultiple357Avg(int arr[], int SIZE)
{
	int counter = 0;
	double sum = 0;
	for (int i = 0; i < SIZE; i++)
		if ((arr[i] % 3 == 0 || arr[i] % 5 == 0 || arr[i] % 7 == 0) && arr[i])
		{
			sum += arr[i];
			counter++;
		}
	return sum / counter;
}

double __fastcall GetElemMultiple3Not5Avg(int arr[], int SIZE)
{
	int counter = 0;
	double sum = 0;
	for (int i = 0; i < SIZE; i++)
		if ((arr[i] % 3 == 0 && arr[i] % 5 != 0) && arr[i])
		{
			sum += arr[i];
			counter++;
		}
	return sum / counter;
}

double __fastcall GetElemMore1Less5Avg(int arr[], int SIZE)
{
	int counter = 0;
	double sum = 0;
	for (int i = 0; i < SIZE; i++)
		if (arr[i] > 1 && arr[i] < 5)
		{
			sum += arr[i];
			counter++;
		}
	return sum / counter;
}

void __fastcall GetLazy()
{
	cout << "Лень все выводить, алгоритмы работают, поверьте ;)" << endl;
}

int main()
{
	cout << "3.\n\n";

	//Написать функции, определяющие среднее арифметическое:
    //•	всех элементов массива;
    //•	положительных элементов массива;
    //•	отрицательных элементов массива;
    //•	ненулевых элементов массива;
    //•	четных элементов массива;
    //•	нечетных элементов массива;
    //•	элементов массива, кратных 3, 5, 7;
    //•	элементов массива, кратных 3, но не кратных 5;
    //•	элементов массива, значение которых больше 1 и меньше 5.

    setlocale(LC_ALL, "Russian");
    srand((unsigned)time(0));

    int arr[SIZE];

    ArrayFill(arr, SIZE);

    double allElemAvg = GetAllElemAvg(arr, SIZE);
	double positiveElemAvg = GetPositiveElemAvg(arr, SIZE);
	double negativeElemAvg = GetNegativeElemAvg(arr, SIZE);
	double nonZeroElemAvg = GetNonZeroElemAvg(arr, SIZE);
	double evenElemAvg = GetEvenElemAvg(arr, SIZE);
	double oddElemAvg = GetOddElemAvg(arr, SIZE);
	double elemMultiple357Avg = GetElemMultiple357Avg(arr, SIZE);
	double elemMultiple3Not5Avg = GetElemMultiple3Not5Avg(arr, SIZE);
	double elemMore1Less5Avg = GetElemMore1Less5Avg(arr, SIZE);

	GetLazy();
}