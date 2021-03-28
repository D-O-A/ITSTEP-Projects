#include <iostream>
#include <ctime>
using namespace std;

const int SIZE{ 10 };

void ArrayFill(int arr[], int SIZE)
{
	for (int i = 0; i < SIZE; i++)
		arr[i] = rand() % 30 - 11;
}

int GetMinMaxElemDifference(int arr[], int SIZE)
{
	int minElem = arr[0];
	int maxElem = arr[0];
	for (int i = 1; i < SIZE; i++)
	{
		if (arr[i] < minElem)
			minElem = arr[i];
		if (arr[i] > maxElem)
			maxElem = arr[i];
	}
	// проверка необходима для "сопровождения" кода, для корректного возврата значения
	if (minElem < 0)
		minElem = -minElem;
	return maxElem - minElem;
}

void PrintDifference(int differenceMinMax)
{
	cout << "Разница между минимальным и максимальным элементом = " << differenceMinMax << endl;
}

int main()
{
	cout << "5.\n\n";

	//Написать функцию, которая определяет разницу между минимальным и максимальным элементами массива.

	setlocale(LC_ALL, "Russian");
	srand((unsigned)time(0));

	int arr[SIZE];

	ArrayFill(arr, SIZE);

	int differenceMinMax = GetMinMaxElemDifference(arr, SIZE);

	PrintDifference(differenceMinMax);
}