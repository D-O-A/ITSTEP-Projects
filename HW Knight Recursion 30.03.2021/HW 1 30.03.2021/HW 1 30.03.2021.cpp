#include <iostream>
#include <iomanip>
using namespace std;

//���� 8�8 �� �� �������, �� ��� �������, �� ���������� ����� (� ��� � �� ��������)
const int SIZE{ 6 };
const int MOVERANGE{ 8 };

bool CheckMoves(int chessboard[][SIZE], int nextRow, int nextCol)
{
	//�������� �������� �� ��������� ���
	if (chessboard[nextRow][nextCol] == 0 && (nextRow >= 0 && nextRow < MOVERANGE && nextCol >= 0 && nextCol < MOVERANGE))
		return true;
	else
		return false;
}

bool GetKnightMove(int chessboard[][SIZE], int moveRow[], int moveCol[], int y, int x, int move)
{
	//������� ������ �� ��������
	if (move == SIZE * SIZE)
		return true;

	//������� ��������� �����
	for (int i = 0; i < MOVERANGE; i++)
	{
		int nextRow = y + moveRow[i];
	    int nextCol = x + moveCol[i];

		//�������� ���������� ����
		if (CheckMoves(chessboard, nextRow, nextCol))
		{
			move++;
			chessboard[nextRow][nextCol] = move;
			//���� � ��������, ���� ��������� �������� �������� true �� ������� CheckMoves, �� ���������� true ���� �� ������
			//�� ������� ������ �� ��������. � ��������� ������ "����������" ��� ��� � ���������� ���������� ���������
			//�������� ��������� �����
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

	//���� ��������� ����� �������� 8�8 � ��������� ����. 
	//��������� ������ ��������� � ������������ ���������� ������ ���� � ��������� ���� ����.
	//������ ���������: ����� � ������� ���� ����, ��� ������� �� ������� ��� ������ �����, ��������� � ������ ������ ������ ���� ���. 
	//(��� ��� ������� ��������� ���� ��� ������ ��������� ������ ����� ����������, �� �������� ������� ���������� ������ �� ���� �������� 6�6).

	setlocale(LC_ALL, "Russian");

	int chessboard[SIZE][SIZE]{};
	//��������� ���� ����
	int moveRow[MOVERANGE]{ -2, -2, -1, -1, 2, 2, 1, 1 };
	int moveCol[MOVERANGE]{ 1, -1, -2, 2, 1, -1, 2, -2 };

	int y;
	int x;

	//���������� 6,6 ������� ������, ��� ������ �� ������� �������, � ��� ���� ������ ��������. �.�.
	//�� ��������� ����� � ��� ���� �� 6,6 (1,1), � � ������� 5,5 (��� 0,0)
	cout << "������� ����������:\n";
    cin >> y >> x;
	cout << endl;

	// ����� ���������� � ������� "������ ���"
	chessboard[y][x] = 1; 
	// �� � ��� �� ���������� ������� �����
	int move = 1;   

	GetKnightMove(chessboard, moveRow, moveCol, y, x, move);

	PrintArray(chessboard, SIZE);
}