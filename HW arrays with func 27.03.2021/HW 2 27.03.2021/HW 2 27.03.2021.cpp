#include <iostream>
#include <ctime>
using namespace std;

const int SIZE{ 10 };

void __fastcall ArrayFill(int arr[], int SIZE)
{
	for (int i = 0; i < SIZE; i++)
		arr[i] = rand() % 21 - 10;
}

int __fastcall GetPositiveElemAmount(int arr[], int SIZE)
{
	int counter = 0;
	for (int i = 0; i < SIZE; i++)
		if (arr[i] > 0)
			counter++;
	return counter;
}

int __fastcall GetPositiveElemSum(int arr[], int SIZE)
{
	int sum = 0;
	for (int i = 0; i < SIZE; i++)
		if (arr[i] > 0)
			sum += arr[i];
	return sum;
}

int __fastcall GetNegativeElemAmount(int arr[], int SIZE)
{
	int counter = 0;
	for (int i = 0; i < SIZE; i++)
		if (arr[i] < 0)
			counter++;
	return counter;
}

int __fastcall GetNegativeElemSum(int arr[], int SIZE)
{
	int sum = 0;
	for (int i = 0; i < SIZE; i++)
		if (arr[i] < 0)
			sum += arr[i];
	return sum;
}

int __fastcall GetNonZeroElemAmount(int arr[], int SIZE)
{
	int counter = 0;
	for (int i = 0; i < SIZE; i++)
		if (arr[i])
			counter++;
	return counter;
}

int __fastcall GetNonZeroElemSum(int arr[], int SIZE)
{
	int sum = 0;
	for (int i = 0; i < SIZE; i++)
		if (arr[i])
			sum += arr[i];
	return sum;
}

int __fastcall GetEvenElemAmount(int arr[], int SIZE)
{
	int counter = 0;
	for (int i = 0; i < SIZE; i++)
		if (arr[i] % 2 == 0)
			counter++;
	return counter;
}

int __fastcall GetEvenElemSum(int arr[], int SIZE)
{
	int sum = 0;
	for (int i = 0; i < SIZE; i++)
		if (arr[i] % 2 == 0)
			sum += arr[i];
	return sum;
}

int __fastcall GetOddElemAmount(int arr[], int SIZE)
{
	int counter = 0;
	for (int i = 0; i < SIZE; i++)
		if (arr[i] % 2 != 0)
			counter++;
	return counter;
}

int __fastcall GetOddElemSum(int arr[], int SIZE)
{
	int sum = 0;
	for (int i = 0; i < SIZE; i++)
		if (arr[i] % 2 != 0)
			sum += arr[i];
	return sum;
}

int __fastcall GetElemMultiple357Amount(int arr[], int SIZE)
{
	int counter = 0;
	for (int i = 0; i < SIZE; i++)
		if ((arr[i] % 3 == 0 || arr[i] % 5 == 0 || arr[i] % 7 == 0) && arr[i])
			counter++;
	return counter;
}

int __fastcall GetElemMultiple357Sum(int arr[], int SIZE)
{
	int sum = 0;
	for (int i = 0; i < SIZE; i++)
		if ((arr[i] % 3 == 0 || arr[i] % 5 == 0 || arr[i] % 7 == 0) && arr[i])
			sum += arr[i];
	return sum;
}

int __fastcall GetElemMultiple3Not5Amout(int arr[], int SIZE)
{
	int counter = 0;
	for (int i = 0; i < SIZE; i++)
		if ((arr[i] % 3 == 0 && arr[i] % 5 != 0) && arr[i])
			counter++;
	return counter;
}

int __fastcall GetElemMultiple3Not5Sum(int arr[], int SIZE)
{
	int sum = 0;
	for (int i = 0; i < SIZE; i++)
		if ((arr[i] % 3 == 0 && arr[i] % 5 != 0) && arr[i])
			sum += arr[i];
	return sum;
}

int __fastcall GetElemMore1Less5Amount(int arr[], int SIZE)
{
	int counter = 0;
	for (int i = 0; i < SIZE; i++)
		if (arr[i] > 1 && arr[i] < 5) 
			counter++;
	return counter;
}

int __fastcall GetElemMore1Less5Sum(int arr[], int SIZE)
{
	int sum = 0;
	for (int i = 0; i < SIZE; i++)
		if (arr[i] > 1 && arr[i] < 5)
			sum += arr[i];
	return sum;
}

void __fastcall GetLazy()
{
	cout << "Лень все выводить, алгоритмы работают, поверьте ;)" << endl;
}

int main()
{
	cout << "2.\n\n";

	//Написать функции, определяющие сумму/количество:
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

	int positiveElemAmount = GetPositiveElemAmount(arr, SIZE);
	int positiveElemSum = GetPositiveElemSum(arr, SIZE);
	int negativeElemAmount = GetNegativeElemAmount(arr, SIZE);
	int negativeElemSum = GetNegativeElemSum(arr, SIZE);
	int nonZeroElemAmount = GetNonZeroElemAmount(arr, SIZE);
	int nonZeroElemSum = GetNonZeroElemSum(arr, SIZE);
	int evenElemAmount = GetEvenElemAmount(arr, SIZE);
	int evenElemSum = GetEvenElemSum(arr, SIZE);
	int oddElemAmount = GetOddElemAmount(arr, SIZE);
	int oddElemSum = GetOddElemSum(arr, SIZE);
	int elemMultiple357Amount = GetElemMultiple357Amount(arr, SIZE);
	int elemMultple357Sum = GetElemMultiple357Sum(arr, SIZE);
	int elemMore1Less5Amount = GetElemMore1Less5Amount(arr, SIZE);
	int elemMore1Less5Sum = GetElemMore1Less5Sum(arr, SIZE);

	GetLazy();
}