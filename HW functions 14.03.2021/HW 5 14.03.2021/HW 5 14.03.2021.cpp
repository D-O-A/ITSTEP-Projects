#include <iostream>
using namespace std;

bool UpperRegister(char symbol)
{
	char lower = 97, upper = 64;   // ������ ������� � ������ ���������
	if (symbol > upper && symbol < lower)
		return true;
	else
		return false;
}

int main()
{
	cout << "5.\n\n";

	//�������� ���������� �������, ������� �������� ���������� �������� � ���������� true,
	//���� ��������� ������ �������� ������ �������� ��������, � false � ��������� ������.

	setlocale(LC_ALL, "Russian");

	cout << "Enter a letter:\n";
	char letter, upper = 64, letterEnd = 122;
	cin >> letter;

	if (letter < upper || letter > 122)   // #�������
		cout << "���� ������ �� �������� ������.\n";
	else if (UpperRegister(letter))
		cout << "��� ������ �������� ������ �������� ��������.\n";
	else
		cout << "���� ������ �������� ������ ������� ��������.\n";
}