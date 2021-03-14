#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
	cout << "11.\n\n";

	//Во всех задачах дан массив 3х3 или 5х5 элементов типа int, которые вводятся пользователем с
	//клавиатуры или задаются явно при инициализации.
	//Написать программу, которая сортирует элементы внутри столбцов двумерного массива.

	setlocale(LC_ALL, "Russian");

	const int ROW{ 5 }, COLUMN{ 5 };
	int arr[ROW][COLUMN];
	srand((unsigned)time(0));

	for (int i = 0; i < ROW; i++)   //заполняем массив случайными значениями
		for (int j = 0; j < COLUMN; j++)
			arr[i][j] = rand() % 20 - 5;

	for (int i = 0; i < ROW; i++)   //выводим массив 
	{
		for (int j = 0; j < COLUMN; j++)
			cout << setw(3) << arr[i][j] << "  ";
		cout << endl;
	}
	cout << endl;

	for (int n = 0; n < ROW; n++)   // сортируем столбцы
	{
		for (int i = 1; i < ROW; i++)   // insertion sort
		{
			int temp = arr[i][n];
			int j = i - 1;
			while (j >= 0 && arr[j][n] > temp)
			{
				arr[j + 1][n] = arr[j][n];
				j--;
			}
			arr[j + 1][n] = temp;
		}
	}

	for (int i = 0; i < ROW; i++)   //выводим массив 
	{
		for (int j = 0; j < COLUMN; j++)
			cout << setw(3) << arr[i][j] << "  ";
		cout << endl;
	}
	cout << endl;
}