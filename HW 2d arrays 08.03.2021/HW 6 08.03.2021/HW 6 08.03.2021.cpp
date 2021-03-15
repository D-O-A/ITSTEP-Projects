#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
	cout << "6.\n\n";

	//Во всех задачах дан массив 3х3 или 5х5 элементов типа int, которые вводятся пользователем с
	//клавиатуры или задаются явно при инициализации.
	//Написать программу, которая находит строки двумерного массива, которые содержат
	//минимальный и максимальный элементы, и меняющую эти строки местами.

	setlocale(LC_ALL, "Russian");

	const int ROW{ 5 }, COLUMN{ 5 };
	int arr[ROW][COLUMN];
	int minIndexRow = 0, minIndexCol = 0, maxIndexRow = 0, maxIndexCol = 0;
	srand((unsigned)time(0));

	for (int i = 0; i < ROW; i++)   //заполняем массив случайными значениями
		for (int j = 0; j < COLUMN; j++)
			arr[i][j] = rand() % 30 - 7;

	int minElem = arr[0][0], maxElem = arr[0][0];

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

	for (int i = 0; i < ROW; i++)   //выводим массив 
	{
		for (int j = 0; j < COLUMN; j++)
			cout << setw(3) << arr[i][j] << "  ";
		cout << endl;
	}
	cout << endl;

	cout << "Min element = [" << minIndexRow << "][" << minIndexCol << "]\n"   // выводим индексы минимального и максимального элемента
		 << "Max element = [" << maxIndexRow << "][" << maxIndexCol << "]\n\n";

	if (minIndexRow == maxIndexRow)
		cout << "Минимальный и максимальный элемент находится в одной строке, нечего менять." << endl;
	else
	{
		swap(arr[minIndexRow], arr[maxIndexRow]);   // #мегачитер

		for (int i = 0; i < ROW; i++)   //выводим массив с замененными строками
		{
			for (int j = 0; j < COLUMN; j++)
				cout << setw(3) << arr[i][j] << "  ";
			cout << endl;
		}
	}
}