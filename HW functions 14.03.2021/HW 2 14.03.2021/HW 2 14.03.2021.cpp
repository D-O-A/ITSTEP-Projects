#include <iostream>
using namespace std;

int Min(int num1, int num2)
{
	if (num1 <= num2)
		return num1;
	else
		return num2;
}

int main()
{
	cout << "2.\n\n";

	//�������� �������, ������� ������� ������� �� ���� ����� �����.

	setlocale(LC_ALL, "Russian");

	int num1, num2;
	cout << "������� 2 �����:\n";
	cin >> num1 >> num2;
	cout << "������� ����� = " << Min(num1, num2) << endl;
}