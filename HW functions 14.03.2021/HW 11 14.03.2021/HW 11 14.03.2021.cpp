#include <iostream>
using namespace std;

int Factorial(int num)
{
	int f = 1;
	for (int i = 1; i <= num ; i++)
		f *= i;
	return f;
}

int main()
{
	cout << "11.\n\n";
	//�������� �������, ����������� ��������� ��������� ��������.
	setlocale(LC_ALL, "Russian");
	int num;
	cout << "������� �����:"; cin >> num;
	cout << "��������� ��������� ����� = " << Factorial(num) << endl;
}