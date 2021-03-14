#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
	cout << "7.\n\n";

	//�� ���� ������� ��� ������ 3�3 ��� 5�5 ��������� ���� int, ������� �������� ������������� �
	//���������� ��� �������� ���� ��� �������������.
	//�������� ���������, ������������ ������� ������� ���������� �������, �������
	//�������� ����������� � ������������ ��������, � �������� ��� ������� �������.


	setlocale(LC_ALL, "Russian");

	const int ROW{ 5 }, COLUMN{ 5 };
	int arr[ROW][COLUMN];
	int minIndexRow = 0, minIndexCol = 0, maxIndexRow = 0, maxIndexCol = 0;
	srand((unsigned)time(0));

	for (int i = 0; i < ROW; i++)   //��������� ������ ���������� ����������
		for (int j = 0; j < COLUMN; j++)
			arr[i][j] = rand() % 45 - 10;

	int minElem = arr[0][0], maxElem = arr[0][0];

	for (int i = 0; i < ROW; i++)   //������� ������� �������� � ��������� ���������
	{
		for (int j = 0; j < COLUMN; j++)
		{
			if (arr[i][j] > maxElem)
				maxIndexRow = i, maxIndexCol = j, maxElem = arr[i][j];
			if (arr[i][j] < minElem)
				minIndexRow = i, minIndexCol = j, minElem = arr[i][j];
		}
	}

	for (int i = 0; i < ROW; i++)   //������� ������ 
	{
		for (int j = 0; j < COLUMN; j++)
			cout << setw(3) << arr[i][j] << "  ";
		cout << endl;
	}
	cout << endl;

	cout << "Min element = [" << minIndexRow << "][" << minIndexCol << "]\n"   // ������� ������� ������������ � ������������� ��������
		 << "Max element = [" << maxIndexRow << "][" << maxIndexCol << "]\n\n";

	for (int i = 0; i < ROW; i++)   // ������ ������� �������
	{
		swap(arr[i][minIndexCol], arr[i][maxIndexCol]);
	}
	cout << endl;

	for (int i = 0; i < ROW; i++)   //������� ������ � ����������� ���������
	{
		for (int j = 0; j < COLUMN; j++)
			cout << setw(3) << arr[i][j] << "  ";
		cout << endl;
	}
	cout << endl;
}