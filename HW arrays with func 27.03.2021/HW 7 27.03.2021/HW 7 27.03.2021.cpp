#include <iostream>
#include <ctime>
using namespace std;

const int SIZE{ 20 };

void ArrayFill(int arr[], int SIZE)
{
	for (int i = 0; i < SIZE; i++)
		arr[i] = rand() % 42;
}

bool PrimeCheck(int element)
{
	// отсеиваем непростые числа и передаем результат в другую функцию
	if (element <= 1)
		return false;
	for (int i = 2; i < element; i++)
		if (element % i == 0)
			return false;
	return true;
}

int GetPrimeNumberAmount(int arr[], int SIZE)
{
	// передаем каждый элемент массива на проверку делителя в другую функцию
	int counter = 0;
	for (int i = 0; i < SIZE; i++)
		if (PrimeCheck(arr[i]))
			counter++;
	return counter;
}

void PrintPrimeNumberAmount(int primeNumberAmount)
{
	cout << "Количество простых чисел в массиве = " << primeNumberAmount << endl;
}

int main()
{
	cout << "7.\n\n";

	//Написать функцию, которая возвращает количество простых чисел в передаваемом ей массиве.

	setlocale(LC_ALL, "Russian");
	srand((unsigned)time(0));

	int arr[SIZE];

	ArrayFill(arr, SIZE);

	int primeNumberAmount = GetPrimeNumberAmount(arr, SIZE);

	PrintPrimeNumberAmount(primeNumberAmount);
}