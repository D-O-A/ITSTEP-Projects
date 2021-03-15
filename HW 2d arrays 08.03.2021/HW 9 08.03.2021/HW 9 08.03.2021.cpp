#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << "9.\n\n";

	//Во всех задачах дан массив 3х3 или 5х5 элементов типа int, которые вводятся пользователем с
	//клавиатуры или задаются явно при инициализации.
	//Написать программу, которая циклически сдвигает столбцы двумерного массива вправо
	//(т.е. 1 - й столбец становится на место 2 - го, 2 - й - на место 3 - го, ..., последний - на место 1 - го).


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

	for (int i = 0; i < ROW; i++)   // магия по замену столбцов
	{
		for (int j = 1; j < COLUMN; j++)
		{
			int temp = arr[i][j];
			arr[i][j] = arr[i][0];
			arr[i][0] = temp;
		}
	}

	for (int i = 0; i < ROW; i++)   //выводим массив с замененными столбцами
	{
		for (int j = 0; j < COLUMN; j++)
			cout << setw(3) << arr[i][j] << "  ";
		cout << endl;
	}
	cout << endl;
}