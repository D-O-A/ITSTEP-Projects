#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cout << "5.\n\n";

	//¬о всех задачах дан массив 3х3 или 5х5 элементов типа int, которые ввод€тс€ пользователем с
	//клавиатуры или задаютс€ €вно при инициализации.
	//Ќаписать программу, котора€ определ€ет сумму значений, наход€щихс€ в массиве
	//между минимальным и максимальным элементами двумерного массива.

	setlocale(LC_ALL, "Russian");

	const int ROW{ 5 }, COLUMN{ 5 };
	int arr[ROW][COLUMN];
	int minIndexRow = 0, minIndexCol = 0, maxIndexRow = 0, maxIndexCol = 0, sum = 0;
	srand((unsigned)time(0));

	for (int i = 0; i < ROW; i++)   //заполн€ем массив случайными значени€ми
		for (int j = 0; j < COLUMN; j++)
			arr[i][j] = rand() % 60 - 20;

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
		for (int j = 0; j < COLUMN; j++)
			cout << "arr[" << i << "][" << j << "] = " << arr[i][j] << endl;

	cout << endl;

	if (minIndexRow > maxIndexRow || minIndexRow >= maxIndexRow && minIndexCol > maxIndexCol)   // мен€ем местами если минимальный элемент идет после максимального
	{
		swap(minIndexRow, maxIndexRow);
		swap(minIndexCol, maxIndexCol);
	}
	cout << endl;

	cout << "Min element = [" << minIndexRow << "][" << minIndexCol << "]\n"   // выводим индексы минимального и максимального элемента
		 << "Max element = [" << maxIndexRow << "][" << maxIndexCol << "]\n";

	int n;
	if (minIndexCol == COLUMN - 1)   // делаем магию с правильным началом суммировани€ элементов
		minIndexRow += 1, n = 0;
	else
		n = minIndexCol + 1;

	for (int i = minIndexRow; i <= maxIndexRow; i++)   // рабочий, суммируем элементы
	{
		if (i != minIndexRow)
			n = 0;
		for (int j = n; j < COLUMN; j++)
		{
			if (i == maxIndexRow && j == maxIndexCol)
				break;
			sum += arr[i][j];
	    }
	}
	cout << "sum = " << sum << endl;
}