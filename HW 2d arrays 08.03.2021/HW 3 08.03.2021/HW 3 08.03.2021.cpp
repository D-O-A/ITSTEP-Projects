#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int main()
{
	cout << "3.\n\n";

	//Во всех задачах дан массив 3х3 или 5х5 элементов типа int, которые вводятся пользователем с
	//клавиатуры или задаются явно при инициализации.
	//Написать программу, которая определяет значения и индексы минимума и максимума
	//элементов двумерного массива и меняет их местами.

	setlocale(LC_ALL, "Russian");

	const int ROW{ 5 }, COLUMN{ 5 };
	int arr[ROW][COLUMN];
	int minIndexRow = 0, minIndexCol = 0, maxIndexRow = 0, maxIndexCol = 0;
	srand((unsigned)time(0));

	for (int i = 0; i < ROW; i++)   //заполняем массив случайными значениями
		for (int j = 0; j < COLUMN; j++)
			arr[i][j] = rand() % 60 - 20;
	
	int minElem = arr[0][0], maxElem = arr[0][0];

	for (int i = 0; i < ROW; i++)   //выводим массив
		for (int j = 0; j < COLUMN; j++)
			cout << "arr[" << i << "][" << j << "] = " << arr[i][j] << endl;

	cout << endl;

	for (int i = 0; i < ROW; i++)   //находим индексы минимума и максимума элементов
	{
		for (int j = 0; j < COLUMN; j++)
		{
			if (arr[i][j] > maxElem)
				maxIndexRow = i, maxIndexCol = j, maxElem = arr[i][j];
			if (arr[i][j] < minElem)
				minIndexRow = i, minIndexCol = j, minElem = arr[i][j];
		}
	}

	//#читерство
	swap(arr[minIndexRow][minIndexCol], arr[maxIndexRow][maxIndexCol]);   //функция из библиотеки algorithm, меняет местами значения 
	//можно и так, но зачем
	//int temp = arr[minIndexRow][minIndexCol];
	//arr[minIndexRow][minIndexCol] = arr[maxIndexRow][maxIndexCol];
	//arr[maxIndexRow][maxIndexCol] = temp;

	for (int i = 0; i < ROW; i++)   //выводим массив с замененными значениями
		for (int j = 0; j < COLUMN; j++)
			cout << "arr[" << i << "][" << j << "] = " << arr[i][j] << endl;

	cout << endl;
	cout << "Были заменены элементы с индексами arr[" << minIndexRow << "][" << minIndexCol << "] и arr[" << maxIndexRow << "][" << maxIndexCol << "].\n"
		 << "Минимальный элемент = " << minElem << endl << "Минимальный элемент = " << maxElem << endl;
}