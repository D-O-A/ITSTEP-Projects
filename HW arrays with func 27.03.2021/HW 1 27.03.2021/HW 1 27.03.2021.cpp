#include <iostream>
#include <ctime>
using namespace std;

const int SIZE = 10;

void ArrayFill(int arr[], int SIZE)
{
	for (int i = 0; i < SIZE; i++)
		arr[i] = rand() % 5;
}

int GetUserNum()
{
	int num;
	cout << "������� �����:"; cin >> num;
	return num;
}

int FindUserNum(int arr[], int SIZE, int num) 
{
	int counter = 0;
	for (int i = 0; i < SIZE; i++)
		if (arr[i] == num)
			counter++;
	return counter;
}

void PrintCounter(int counter)
{
	cout << "���� ����� ����������� � ������� " << counter << " ���(�)." << endl;
}


int main()
{
	cout << "1.\n\n";

	//�������� �������, ������� ������� ������� ��� �������� ����� ����������� � �������.

	setlocale(LC_ALL, "Russian");
	srand((unsigned)time(0));

	int arr[SIZE];

	ArrayFill(arr, SIZE);

	int num = GetUserNum();
	int counter = FindUserNum(arr, SIZE, num);

	PrintCounter(counter);
}