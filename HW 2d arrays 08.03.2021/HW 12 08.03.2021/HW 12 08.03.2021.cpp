#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << "12.\n\n";

	//Во всех задачах дан массив 3х3 или 5х5 элементов типа int, которые вводятся пользователем с
	//клавиатуры или задаются явно при инициализации.
	//Написать программу, которая складывает две матрицы, получает третью матрицу и выводит
	//ее на экран.Сумма двух прямоугольных матриц одинаковых размеров определяется как прямоугольная
	//матрица тех же размеров, элементы которой определяются так : C[i, j] = A[i, j] + B[i, j].

	setlocale(LC_ALL, "Russian");

	const int ROW{ 5 }, COLUMN{ 5 };
	int A[ROW][COLUMN], B[ROW][COLUMN], C[ROW][COLUMN]{};
	srand((unsigned)time(0));

	for (int i = 0; i < ROW; i++)   //заполняем матрицы случайными значениями
		for (int j = 0; j < COLUMN; j++)
		{
			A[i][j] = rand() % 35 - 6;
			B[i][j] = rand() % 10 + 3;
		}

	for (int i = 0; i < ROW; i++)   //выводим массив A
	{
		for (int j = 0; j < COLUMN; j++)
			cout << setw(3) << A[i][j] << "  ";
		cout << endl;
	}
	cout << endl;
	
	cout << "\t + \n\n";

	for (int i = 0; i < ROW; i++)   //выводим массив B
	{
		for (int j = 0; j < COLUMN; j++)
			cout << setw(3) << B[i][j] << "  ";
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < ROW; i++)   // складываем матрицы
		for (int j = 0; j < COLUMN; j++)
			C[i][j] = A[i][j] + B[i][j];

	cout << "\t = \n\n";

	for (int i = 0; i < ROW; i++)   //выводим новую матрицу
	{
		for (int j = 0; j < COLUMN; j++)
			cout << setw(3) << C[i][j] << "  ";
		cout << endl;
	}
	cout << endl;
}