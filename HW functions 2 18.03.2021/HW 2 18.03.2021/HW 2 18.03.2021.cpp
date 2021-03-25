#include <iostream>
#include <ctime>
using namespace std;

const int SIZE = 4;

void RiddleMeThis(int arr[], int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 9 + 1;
	}

	for (int n = 0; n < SIZE; n++)   // алгоритм отсеивания повторяющихся чисел
	{
		for (int j = 0; j < SIZE; j++)
		{
			for (int i = j + 1; i < SIZE; i++)
			{
				if (arr[i] == arr[j])
				{
					arr[i] = rand() % 9 + 1;
				}
			}
		}
	}
}

int GetUserNum()
{
	int num;
	//Пользователь должен ввести четырехзначное число, которое не может начинаться с 0 и в котором не могут повторяться числа.
	//перекладываем ответственность за корректный ввод числа на пользователя.
	cout << "Загадайте четырехзначное число:"; cin >> num;
	return num;
}

void ConvertUserInput(int brr[], int SIZE, int userNum)
{
	brr[0] = userNum / 1000;   // Заполняем второй массив загаданным пользователем числом
	brr[1] = userNum / 100 % 10;
	brr[2] = userNum / 10 % 10;
	brr[3] = userNum % 10;
}

int GetCows(int arr[], int brr[], int SIZE)
{
	int numMatch = 0;   // считаем кол-во "коров"
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			if (arr[i] == brr[j])
				numMatch++;
	return numMatch;
}

int GetBulls(int arr[], int brr[], int SIZE)
{
	int indexMatch = 0;   // считаем кол-во "быков"
	for (int i = 0; i < SIZE; i++)
		if (arr[i] == brr[i])
			indexMatch++;
	return indexMatch;
}

void PrintResult(int cows, int bulls)  
{
	cout << cows << " угадал, " << bulls << " стоят на верных позициях" << endl;
}

int main()
{
	cout << "2.\n\n";

	//Переоформить игру "Быки и коровы" в соответствии с парадигмой процедурного программирования.

	setlocale(LC_ALL, "Russian");
	srand((unsigned)time(0));
	
	int arr[SIZE], brr[SIZE];
	int cows, bulls;

	RiddleMeThis(arr, SIZE);

	//for (int i = 0; i < SIZE; i++)   // для дебага, выводит загаданное число
	//{
	//	cout << arr[i];
	//}   
	//cout << endl;

	do
	{
		int userNum = GetUserNum();
		ConvertUserInput(brr, SIZE, userNum);

		cows = GetCows(arr, brr, SIZE);
		bulls = GetBulls(arr, brr, SIZE);

		PrintResult(cows, bulls);

		if (cows == 4 && bulls == 4)
		{
			cout << "Ты выиграл :)\n";
			break;
		}
		else
			cout << "Попробуй еще раз :(\n";

		cout << endl;
	} while (true);
}