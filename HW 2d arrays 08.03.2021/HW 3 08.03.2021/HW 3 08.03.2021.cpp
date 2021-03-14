#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int main()
{
	cout << "3.\n\n";

	//�� ���� ������� ��� ������ 3�3 ��� 5�5 ��������� ���� int, ������� �������� ������������� �
	//���������� ��� �������� ���� ��� �������������.
	//�������� ���������, ������� ���������� �������� � ������� �������� � ���������
	//��������� ���������� ������� � ������ �� �������.

	setlocale(LC_ALL, "Russian");

	const int ROW{ 5 }, COLUMN{ 5 };
	int arr[ROW][COLUMN];
	int minIndexRow = 0, minIndexCol = 0, maxIndexRow = 0, maxIndexCol = 0;
	srand((unsigned)time(0));

	for (int i = 0; i < ROW; i++)   //��������� ������ ���������� ����������
		for (int j = 0; j < COLUMN; j++)
			arr[i][j] = rand() % 60 - 20;
	
	int minElem = arr[0][0], maxElem = arr[0][0];

	for (int i = 0; i < ROW; i++)   //������� ������
		for (int j = 0; j < COLUMN; j++)
			cout << "arr[" << i << "][" << j << "] = " << arr[i][j] << endl;

	cout << endl;

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

	//#���������
	swap(arr[minIndexRow][minIndexCol], arr[maxIndexRow][maxIndexCol]);   //������� �� ���������� algorithm, ������ ������� �������� 
	//����� � ���, �� �����
	//int temp = arr[minIndexRow][minIndexCol];
	//arr[minIndexRow][minIndexCol] = arr[maxIndexRow][maxIndexCol];
	//arr[maxIndexRow][maxIndexCol] = temp;

	for (int i = 0; i < ROW; i++)   //������� ������ � ����������� ����������
		for (int j = 0; j < COLUMN; j++)
			cout << "arr[" << i << "][" << j << "] = " << arr[i][j] << endl;

	cout << endl;
	cout << "���� �������� �������� � ��������� arr[" << minIndexRow << "][" << minIndexCol << "] � arr[" << maxIndexRow << "][" << maxIndexCol << "].\n"
		 << "����������� ������� = " << minElem << endl << "����������� ������� = " << maxElem << endl;
}