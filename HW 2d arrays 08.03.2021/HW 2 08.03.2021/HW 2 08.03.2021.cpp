#include <iostream>
using namespace std;

int main()
{
	cout << "2.\n\n";

	//�� ���� ������� ��� ������ 3�3 ��� 5�5 ��������� ���� int, ������� �������� ������������� �
	//���������� ��� �������� ���� ��� �������������.
	//�������� ���������, ������� ���������� ������������ ��������� ���������� �������.

	setlocale(LC_ALL, "Russian");

	const int ROW{ 3 }, COLUMN{ 3 };
	int arr[ROW][COLUMN];
	int product = 1;

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			cout << "������� �������� [" << i << "][" << j << "]: ";
			cin >> arr[i][j];
		}
	}
	cout << endl;

	for (int i = 0; i < ROW; i++)   // ���������� � ����������� ��������
		for (int j = 0; j < COLUMN; j++)
			product *= arr[i][j];
	

	for (int i = 0; i < ROW; i++)   // ������� ������ � ������������ ���������
		for (int j = 0; j < COLUMN; j++)
			cout << "arr[" << i << "][" << j << "] = " << arr[i][j] << endl;

	cout << "������������ ��������� = " << product << endl;
}