#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << "8.\n\n";

	//�� ���� ������� ��� ������ 3�3 ��� 5�5 ��������� ���� int, ������� �������� ������������� �
	//���������� ��� �������� ���� ��� �������������.
	//�������� ���������, ������� ���������� �������� ������ ���������� ������� ����
	//(�.�. 1 - � ������ ���������� �� ����� 2 - �, 2 - � - �� ����� 3 - �, ..., ��������� - �� ����� 1 - �).

	setlocale(LC_ALL, "Russian");

	const int ROW{ 5 }, COLUMN{ 5 };
	int arr[ROW][COLUMN];
	srand((unsigned)time(0));

	for (int i = 0; i < ROW; i++)   //��������� ������ ���������� ����������
		for (int j = 0; j < COLUMN; j++)
			arr[i][j] = rand() % 22;

	for (int i = 0; i < ROW; i++)   //������� ������ 
	{
		for (int j = 0; j < COLUMN; j++)
			cout << setw(3) << arr[i][j] << "  ";
		cout << endl;
	}
	cout << endl;

	for (int i = 1; i < ROW; i++)   // ����� �� ������ �����
	{
		for (int j = 0; j < COLUMN; j++)
		{
			int temp = arr[i][j];
			arr[i][j] = arr[0][j];
			arr[0][j] = temp;
		}
	}

	for (int i = 0; i < ROW; i++)   //������� ������ � ����������� ��������
	{
		for (int j = 0; j < COLUMN; j++)
			cout << setw(3) << arr[i][j] << "  ";
		cout << endl;
	}
	cout << endl;
}