#include <iostream>
using namespace std;

int main()
{
	cout << "1.\n\n";

	//�� ���� ������� ��� ������ 3�3 ��� 5�5 ��������� ���� int, ������� �������� ������������� �
	//���������� ��� �������� ���� ��� �������������.
	//�������� ���������, ������� ���������� ����� ��������� ���������� �������.

	setlocale(LC_ALL, "Russian");

	const int ROW{ 3 }, COLUMN{ 3 };
	int arr[ROW][COLUMN]{ { 16, 2 ,42}, { 1,0,13 }, { -2, 15,22 } };
	int sum = 0;

	for (int i = 0; i < ROW; i++)   // ���������� � ��������� ��������
		for (int j = 0; j < COLUMN; j++)
			sum += arr[i][j];
		
	for (int i = 0; i < ROW; i++)   // ������� ������ � ����� ���������
		for (int j = 0; j < COLUMN; j++)
			cout << "arr[" << i << "][" << j << "] = " << arr[i][j] << endl;
	
	cout << "����� ��������� = " << sum << endl;
}