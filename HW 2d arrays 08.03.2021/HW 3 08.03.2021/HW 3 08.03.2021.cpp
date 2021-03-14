#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int main()
{
	cout << "3.\n\n";

	//¬о всех задачах дан массив 3х3 или 5х5 элементов типа int, которые ввод€тс€ пользователем с
	//клавиатуры или задаютс€ €вно при инициализации.
	//Ќаписать программу, котора€ определ€ет значени€ и индексы минимума и максимума
	//элементов двумерного массива и мен€ет их местами.

	setlocale(LC_ALL, "Russian");

	const int ROW{ 5 }, COLUMN{ 5 };
	int arr[ROW][COLUMN];
	int minIndexRow = 0, minIndexCol = 0, maxIndexRow = 0, maxIndexCol = 0;
	srand((unsigned)time(0));

	for (int i = 0; i < ROW; i++)   //заполн€ем массив случайными значени€ми
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
	swap(arr[minIndexRow][minIndexCol], arr[maxIndexRow][maxIndexCol]);   //функци€ из библиотеки algorithm, мен€ет местами значени€ 
	//можно и так, но зачем
	//int temp = arr[minIndexRow][minIndexCol];
	//arr[minIndexRow][minIndexCol] = arr[maxIndexRow][maxIndexCol];
	//arr[maxIndexRow][maxIndexCol] = temp;

	for (int i = 0; i < ROW; i++)   //выводим массив с замененными значени€ми
		for (int j = 0; j < COLUMN; j++)
			cout << "arr[" << i << "][" << j << "] = " << arr[i][j] << endl;

	cout << endl;
	cout << "Ѕыли заменены элементы с индексами arr[" << minIndexRow << "][" << minIndexCol << "] и arr[" << maxIndexRow << "][" << maxIndexCol << "].\n"
		 << "ћинимальный элемент = " << minElem << endl << "ћинимальный элемент = " << maxElem << endl;
}