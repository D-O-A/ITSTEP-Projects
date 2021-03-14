#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
	cout << "10.\n\n";

	//¬о всех задачах дан массив 3х3 или 5х5 элементов типа int, которые ввод€тс€ пользователем с
	//клавиатуры или задаютс€ €вно при инициализации.
	//Ќаписать программу, котора€ сортирует элементы внутри строк двумерного массива.

	setlocale(LC_ALL, "Russian");

	const int ROW{ 5 }, COLUMN{ 5 };
	int arr[ROW][COLUMN];
	srand((unsigned)time(0));

	for (int i = 0; i < ROW; i++)   //заполн€ем массив случайными значени€ми
		for (int j = 0; j < COLUMN; j++)
			arr[i][j] = rand() % 20 - 5;

	for (int i = 0; i < ROW; i++)   //выводим массив 
	{
		for (int j = 0; j < COLUMN; j++)
			cout << setw(3) << arr[i][j] << "  ";
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < ROW; i++)   // сортируем элементы внутри строк
		sort(arr[i], arr[i] + ROW);   // #читер

	for (int i = 0; i < ROW; i++)   //выводим массив 
	{
		for (int j = 0; j < COLUMN; j++)
			cout << setw(3) << arr[i][j] << "  ";
		cout << endl;
	}
	cout << endl;
}