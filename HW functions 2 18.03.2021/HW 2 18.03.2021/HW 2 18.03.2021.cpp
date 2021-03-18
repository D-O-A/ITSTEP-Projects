#include <iostream>
#include <ctime>
using namespace std;

int RiddleMeThis()
{
	const int SIZE = 4;
	int arr[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 9 + 1;
	}
	cout << endl;

	for (int n = 0; n < SIZE; n++)   // алгоритм отсеивания повторяющихся чисел
	{
		for (int j = 0; j < SIZE; j++)
		{
			for (int i = j + 1; i < SIZE; i++)
			{
				if (arr[i] == arr[j])
				{
					arr[i] = rand() % 9 + 1;
				}
			}
		}
	}


	for (int i = 0; i < SIZE; i++)
	{
		return arr[i];
	}
}

void PrintArray()
{
	for (int i = 0; i < 4; i++)
	{
		cout << RiddleMeThis();
	}
}




int main()
{
	cout << "2.\n\n";

	//Переоформить игру "Быки и коровы" в соответствии с парадигмой процедурного программирования.

	setlocale(LC_ALL, "Russian");
	srand((unsigned)time(0));
	
	RiddleMeThis();

	PrintArray();
}