#include <iostream>
using namespace std;

int Max(int num1, int num2)
{
	if (num1 >= num2)
		return num1;
	else
		return num2;
}

int main()
{
	cout << "3.\n\n";

	//�������� �������, ������� ������� ������� �� ���� ����� �����.

	setlocale(LC_ALL, "Russian");

	int num1, num2;
	cout << "������� 2 �����:\n";
	cin >> num1 >> num2;
	cout << "������� ����� = " << Max(num1, num2) << endl;
}