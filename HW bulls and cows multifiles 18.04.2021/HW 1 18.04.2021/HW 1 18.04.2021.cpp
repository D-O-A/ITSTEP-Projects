#include <iostream>
#include "HW 1 18.04.2021.h"
using namespace std;

//#define DEBUG

int main()
{
	cout << "2.\n\n";

	//Переоформить игру "Быки и коровы" в соответствии с парадигмой процедурного программирования.

	setlocale(LC_ALL, "Russian");
	srand((unsigned)time(0));

	int arr[SIZE], brr[SIZE];
	int cows, bulls;

	RiddleMeThis(arr, SIZE);

#ifdef DEBUG
	for (int i = 0; i < SIZE; i++)   // для дебага, выводит загаданное число
	{
		cout << arr[i];
	}   
	cout << endl;
#endif 

	do
	{
		int userNum = GetUserNum();
		ConvertUserInput(brr, SIZE, userNum);

		cows = GetCows(arr, brr, SIZE);
		bulls = GetBulls(arr, brr, SIZE);

		PrintResult(cows, bulls);

		if (cows == 4 && bulls == 4)
		{
			cout << "Ты выиграл :)\n";
			break;
		}
		else
			cout << "Попробуй еще раз :(\n";

		cout << endl;
	} while (true);
}