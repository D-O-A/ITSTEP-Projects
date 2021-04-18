#include <iostream>
#include <ctime>
//по приколу)) 
using std::cout;
using std::cin;
using std::endl;

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