#include <iostream>
#include <iomanip>
using namespace std;

//если 8х8 то не считает, ну или считает, но неприлично долго (я так и не дождался)
const int SIZE{ 6 };
const int MOVERANGE{ 8 };

bool CheckMoves(int chessboard[][SIZE], int nextRow, int nextCol)
{
	//проверка возможен ли следующий ход
	if (chessboard[nextRow][nextCol] == 0 && (nextRow >= 0 && nextRow < MOVERANGE && nextCol >= 0 && nextCol < MOVERANGE))
		return true;
	else
		return false;
}

bool GetKnightMove(int chessboard[][SIZE], int moveRow[], int moveCol[], int y, int x, int move)
{
	//условие выхода из рекурсии
	if (move == SIZE * SIZE)
		return true;

	//перебор возможных ходов
	for (int i = 0; i < MOVERANGE; i++)
	{
		int nextRow = y + moveRow[i];
	    int nextCol = x + moveCol[i];

		//проверка следующего хода
		if (CheckMoves(chessboard, nextRow, nextCol))
		{
			move++;
			chessboard[nextRow][nextCol] = move;
			//вход в рекурсию, если следующая итерация получает true из функции CheckMoves, то возвращаем true пока не дойдем
			//до условия выхода из рекурсии. В противном случае "откатываем" наш ход и продолжаем перебирать возможные
			//варианты следующих ходов
			if (GetKnightMove(chessboard, moveRow, moveCol, nextRow, nextCol, move))
				return true;
			move--;
			chessboard[nextRow][nextCol] = 0;
		} 
	}
	return false;
}

void PrintArray(const int chessboard[][SIZE], int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << setw(3) << chessboard[i][j];
		}
		cout << endl;
	}
}

int main()
{
	cout << "1.\n\n";

	//Дана шахматная доска размером 8х8 и шахматный конь. 
	//Программа должна запросить у пользователя координаты клетки поля и поставить туда коня.
	//Задача программы: найти и вывести путь коня, при котором он обойдет все клетки доски, становясь в каждую клетку только один раз. 
	//(Так как процесс отыскания пути для разных начальных клеток может затянуться, то советуем сначала опробовать задачу на поле размером 6х6).

	setlocale(LC_ALL, "Russian");

	int chessboard[SIZE][SIZE]{};
	//возможные ходы коня
	int moveRow[MOVERANGE]{ -2, -2, -1, -1, 2, 2, 1, 1 };
	int moveCol[MOVERANGE]{ 1, -1, -2, 2, 1, -1, 2, -2 };

	int y;
	int x;

	//координаты 6,6 вводить нельзя, ибо выйдем за границы массива, а мне лень делать проверку. Т.е.
	//на шахматной доске у нас было бы 6,6 (1,1), а в массиве 5,5 (или 0,0)
	cout << "Введите координаты:\n";
    cin >> y >> x;
	cout << endl;

	// сразу обозначаем в массиве "первый ход"
	chessboard[y][x] = 1; 
	// ну и тут же обозначаем счетчик ходов
	int move = 1;   

	GetKnightMove(chessboard, moveRow, moveCol, y, x, move);

	PrintArray(chessboard, SIZE);
}