#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << "12.\n\n";

	//�� ���� ������� ��� ������ 3�3 ��� 5�5 ��������� ���� int, ������� �������� ������������� �
	//���������� ��� �������� ���� ��� �������������.
	//�������� ���������, ������� ���������� ��� �������, �������� ������ ������� � �������
	//�� �� �����.����� ���� ������������� ������ ���������� �������� ������������ ��� �������������
	//������� ��� �� ��������, �������� ������� ������������ ��� : C[i, j] = A[i, j] + B[i, j].

	setlocale(LC_ALL, "Russian");

	const int ROW{ 5 }, COLUMN{ 5 };
	int A[ROW][COLUMN], B[ROW][COLUMN], C[ROW][COLUMN]{};
	srand((unsigned)time(0));

	for (int i = 0; i < ROW; i++)   //��������� ������� ���������� ����������
		for (int j = 0; j < COLUMN; j++)
		{
			A[i][j] = rand() % 35 - 6;
			B[i][j] = rand() % 10 + 3;
		}

	for (int i = 0; i < ROW; i++)   //������� ������ A
	{
		for (int j = 0; j < COLUMN; j++)
			cout << setw(3) << A[i][j] << "  ";
		cout << endl;
	}
	cout << endl;
	
	cout << "\t + \n\n";

	for (int i = 0; i < ROW; i++)   //������� ������ B
	{
		for (int j = 0; j < COLUMN; j++)
			cout << setw(3) << B[i][j] << "  ";
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < ROW; i++)   // ���������� �������
		for (int j = 0; j < COLUMN; j++)
			C[i][j] = A[i][j] + B[i][j];

	cout << "\t = \n\n";

	for (int i = 0; i < ROW; i++)   //������� ����� �������
	{
		for (int j = 0; j < COLUMN; j++)
			cout << setw(3) << C[i][j] << "  ";
		cout << endl;
	}
	cout << endl;
}