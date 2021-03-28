#include <iostream>
#include <ctime>
using namespace std;

const int SIZE{ 10 };

void ArrayFill(int arr[], int SIZE)
{
	for (int i = 0; i < SIZE; i++)
		arr[i] = rand() % 20 - 7;
}

int GetMinMaxElemDistance(int arr[], int SIZE)
{
	int minElem = arr[0];
	int maxElem = arr[0];
	int minIndex = 0;
	int maxIndex = 0;

	for (int i = 1; i < SIZE; i++)
	{
		if (arr[i] < minElem)
			minElem = arr[i], minIndex = i;
		if (arr[i] > maxElem)
			maxElem = arr[i], maxIndex = i;
	}

	if (minIndex > maxIndex)
	{
		//swap(minIndex, maxIndex) ;);
		int temp = minIndex;
		minIndex = maxIndex;
		maxIndex = temp;
	}

	int distance = 0;
	for (int i = minIndex + 1; i < maxIndex; i++)
		distance += arr[i];
	return distance;
}

void PrintDistance(int distanceMinMax)
{
	cout << "Расстояние между минимальным и максимальным элементом = " << distanceMinMax << endl;
}

int main()
{
	cout << "6.\n\n";

	//Написать функцию, которая определяет расстояние между минимальным и максимальным элементами массива.

	setlocale(LC_ALL, "Russian");
	srand((unsigned)time(0));

	int arr[SIZE];

	ArrayFill(arr, SIZE);

	int distanceMinMax = GetMinMaxElemDistance(arr, SIZE);

	PrintDistance(distanceMinMax);
}