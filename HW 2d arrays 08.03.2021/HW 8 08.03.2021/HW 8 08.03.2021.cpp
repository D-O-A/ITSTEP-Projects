#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << "8.\n\n";

	//Во всех задачах дан массив 3х3 или 5х5 элементов типа int, которые вводятся пользователем с
	//клавиатуры или задаются явно при инициализации.
	//Написать программу, которая циклически сдвигает строки двумерного массива вниз
	//(т.е. 1 - я строка становится на место 2 - й, 2 - я - на место 3 - й, ..., последняя - на место 1 - й).

	setlocale(LC_ALL, "Russian");

	const int ROW{ 5 }, COLUMN{ 5 };
	int arr[ROW][COLUMN];
	srand((unsigned)time(0));

	for (int i = 0; i < ROW; i++)   //заполняем массив случайными значениями
		for (int j = 0; j < COLUMN; j++)
			arr[i][j] = rand() % 22;

	for (int i = 0; i < ROW; i++)   //выводим массив 
	{
		for (int j = 0; j < COLUMN; j++)
			cout << setw(3) << arr[i][j] << "  ";
		cout << endl;
	}
	cout << endl;

	for (int i = 1; i < ROW; i++)   // магия по замену строк
	{
		for (int j = 0; j < COLUMN; j++)
		{
			int temp = arr[i][j];
			arr[i][j] = arr[0][j];
			arr[0][j] = temp;
		}
	}

	for (int i = 0; i < ROW; i++)   //выводим массив с замененными строками
	{
		for (int j = 0; j < COLUMN; j++)
			cout << setw(3) << arr[i][j] << "  ";
		cout << endl;
	}
	cout << endl;
}