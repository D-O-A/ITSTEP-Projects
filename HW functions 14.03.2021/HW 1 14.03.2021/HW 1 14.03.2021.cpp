#include <iostream>
using namespace std;

int Cube(int num)
{
	return num * num * num;
}

int main()
{
	cout << "1.\n\n";

	//�������� �������, ����������� ��� ������ �����.

	setlocale(LC_ALL, "Russian");

	int num;
	cout << "������� ����� ��� ���������� � ���:"; cin >> num;
	cout << Cube(num) << endl;
}