#include <iostream>
using namespace std;

int main()
{
	cout << "2.\n\n";

	//Во всех задачах дан массив 3х3 или 5х5 элементов типа int, которые вводятся пользователем с
	//клавиатуры или задаются явно при инициализации.
	//Написать программу, которая определяет произведение элементов двумерного массива.

	setlocale(LC_ALL, "Russian");

	const int ROW{ 3 }, COLUMN{ 3 };
	int arr[ROW][COLUMN];
	int product = 1;

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			cout << "Введите значение [" << i << "][" << j << "]: ";
			cin >> arr[i][j];
		}
	}
	cout << endl;

	for (int i = 0; i < ROW; i++)   // перебираем и перемножаем элементы
		for (int j = 0; j < COLUMN; j++)
			product *= arr[i][j];
	

	for (int i = 0; i < ROW; i++)   // выводим массив и произведение элементов
		for (int j = 0; j < COLUMN; j++)
			cout << "arr[" << i << "][" << j << "] = " << arr[i][j] << endl;

	cout << "Произведение элементов = " << product << endl;
}