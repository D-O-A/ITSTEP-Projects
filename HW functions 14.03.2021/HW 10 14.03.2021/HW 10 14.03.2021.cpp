#include <iostream>
#include <algorithm>
using namespace std;

int RangeSum(int num1, int num2)
{
	int sum = 0;
	for (int i = num1 + 1; i < num2; i++)
		sum += i;
	return sum;
}

int main()
{
	cout << "10.\n\n";

	//�������� �������, ����������� ����� ����� ����� �� ��������� ����� ����� ��������� ����������.

	setlocale(LC_ALL, "Russian");

	int num1, num2;
	cout << "������� 2 �����:\n";
	cin >> num1 >> num2;
	if (num1 > num2)
		swap(num1, num2);
	cout << "����� ����� ������� = " << RangeSum(num1, num2) << endl;
}