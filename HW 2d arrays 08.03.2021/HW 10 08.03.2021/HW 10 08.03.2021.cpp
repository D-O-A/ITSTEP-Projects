#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
	cout << "10.\n\n";

	//�� ���� ������� ��� ������ 3�3 ��� 5�5 ��������� ���� int, ������� �������� ������������� �
	//���������� ��� �������� ���� ��� �������������.
	//�������� ���������, ������� ��������� �������� ������ ����� ���������� �������.

	setlocale(LC_ALL, "Russian");

	const int ROW{ 5 }, COLUMN{ 5 };
	int arr[ROW][COLUMN];
	srand((unsigned)time(0));

	for (int i = 0; i < ROW; i++)   //��������� ������ ���������� ����������
		for (int j = 0; j < COLUMN; j++)
			arr[i][j] = rand() % 20 - 5;

	for (int i = 0; i < ROW; i++)   //������� ������ 
	{
		for (int j = 0; j < COLUMN; j++)
			cout << setw(3) << arr[i][j] << "  ";
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < ROW; i++)   // ��������� �������� ������ �����
		sort(arr[i], arr[i] + ROW);   // #�����

	for (int i = 0; i < ROW; i++)   //������� ������ 
	{
		for (int j = 0; j < COLUMN; j++)
			cout << setw(3) << arr[i][j] << "  ";
		cout << endl;
	}
	cout << endl;
}