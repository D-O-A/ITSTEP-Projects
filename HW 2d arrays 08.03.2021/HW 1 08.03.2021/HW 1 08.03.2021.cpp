#include <iostream>
using namespace std;

int main()
{
	cout << "1.\n\n";

	//Во всех задачах дан массив 3х3 или 5х5 элементов типа int, которые вводятся пользователем с
	//клавиатуры или задаются явно при инициализации.
	//Написать программу, которая определяет сумму элементов двумерного массива.

	setlocale(LC_ALL, "Russian");

	const int ROW{ 3 }, COLUMN{ 3 };
	int arr[ROW][COLUMN]{ { 16, 2 ,42}, { 1,0,13 }, { -2, 15,22 } };
	int sum = 0;

	for (int i = 0; i < ROW; i++)   // перебираем и суммируем элементы
		for (int j = 0; j < COLUMN; j++)
			sum += arr[i][j];
		
	for (int i = 0; i < ROW; i++)   // выводим массив и сумму элементов
		for (int j = 0; j < COLUMN; j++)
			cout << "arr[" << i << "][" << j << "] = " << arr[i][j] << endl;
	
	cout << "Сумма элементов = " << sum << endl;
}