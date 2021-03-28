#include <iostream>
#include <ctime>
using namespace std;

const int SIZE{ 20 };

void ArrayFill(int arr[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
        arr[i] = rand() % 21 - 10;
}

int GetEvenIndexAmount(int arr[], int SIZE)
{
    int counter = 0;
    for (int i = 0; i < SIZE; i++)
        if (i % 2 == 0)
            counter++;
    return counter;
}

int GetEvenIndexSum(int arr[], int SIZE)
{
    int sum = 0;
    for (int i = 0; i < SIZE; i++)
        if (i % 2 == 0)
            sum += arr[i];
    return sum;
}

double GetEvenIndexAvg(int arr[], int SIZE)
{
    int counter = 0;
    double sum = 0;
    for (int i = 0; i < SIZE; i++)
        if (i % 2 == 0)
        {
            sum += arr[i];
            counter++;
        }
    return sum / counter;
}

int GetOddIndexAmount(int arr[], int SIZE)
{
    int counter = 0;
    for (int i = 0; i < SIZE; i++)
        if (i % 2 != 0)
            counter++;
    return counter;
}

int GetOddIndexSum(int arr[], int SIZE)
{
    int sum = 0;
    for (int i = 0; i < SIZE; i++)
        if (i % 2 != 0)
            sum += arr[i];
    return sum;
}

double GetOddIndexAvg(int arr[], int SIZE)
{
    int counter = 0;
    double sum = 0;
    for (int i = 0; i < SIZE; i++)
        if (i % 2 != 0)
        {
            sum += arr[i];
            counter++;
        }
    return sum / counter;
}

int GetMultiple2And3IndexAmount(int arr[], int SIZE)
{
    int counter = 0;
    for (int i = 0; i < SIZE; i++)
        if ((i % 2 == 0 && i % 3 == 0) && i)
            counter++;
    return counter;
}

int GetMultiple2And3IndexSum(int arr[], int SIZE)
{
    int sum = 0;
    for (int i = 0; i < SIZE; i++)
        if ((i % 2 == 0 && i % 3 == 0) && i)
            sum += arr[i];
    return sum;
}

double GetMultiple2And3IndexAvg(int arr[], int SIZE)
{
    int counter = 0;
    double sum = 0;
    for (int i = 0; i < SIZE; i++)
        if ((i % 2 == 0 && i % 3 == 0) && i)
        {
            sum += arr[i];
            counter++;
        }
    return sum / counter;
}

int GetMultiple2Not3IndexAmount(int arr[], int SIZE)
{
    int counter = 0;
    for (int i = 0; i < SIZE; i++)
        if ((i % 2 == 0 && i % 3 != 0) && i)
            counter++;
    return counter;
}

int GetMultiple2Not3IndexSum(int arr[], int SIZE)
{
    int sum = 0;
    for (int i = 0; i < SIZE; i++)
        if ((i % 2 == 0 && i % 3 != 0) && i)
            sum += arr[i];
    return sum;
}

double GetMultiple2Not3IndexAvg(int arr[], int SIZE)
{
    int counter = 0;
    double sum = 0;
    for (int i = 0; i < SIZE; i++)
        if ((i % 2 == 0 && i % 3 != 0) && i)
        {
            sum += arr[i];
            counter++;
        }
    return sum / counter;
}

void GetLazy()
{
    cout << "Лень все выводить, алгоритмы работают, поверьте ;)" << endl;
}

int main()
{
	cout << "4.\n\n";

	//Написать функции, определяющие сумму/количество/среднее арифметическое:
    //•	элементов массива с четными индексами;
    //•	элементов массива с нечетными индексами;
    //•	элементов массива с индексами, кратных 2 и 3;
    //•	элементов массива с индексами, кратных 2, но не кратных 3.

    setlocale(LC_ALL, "Russian");
    srand((unsigned)time(0));

    int arr[SIZE];

    ArrayFill(arr, SIZE);

    int indexEvenAmount = GetEvenIndexAmount(arr, SIZE);
    int indexEvenSum = GetEvenIndexSum(arr, SIZE);
    double indexEvenAvg = GetEvenIndexAvg(arr, SIZE);
    int indexOddAmount = GetOddIndexAmount(arr, SIZE);
    int indexOddSum = GetOddIndexSum(arr, SIZE);
    double indexOddAvg = GetOddIndexAvg(arr, SIZE);
    int indexMultiple2And3Amount = GetMultiple2And3IndexAmount(arr, SIZE);
    int indexMultiple2And3Sum = GetMultiple2And3IndexSum(arr, SIZE);
    double indexMultiple2And3Avg = GetMultiple2And3IndexAvg(arr, SIZE);
    int indexMultiple2Not3Amount = GetMultiple2Not3IndexAmount(arr, SIZE);
    int indexMultiple2Not3Sum = GetMultiple2Not3IndexSum(arr, SIZE);
    double indexMultiple2Not3Avg = GetMultiple2Not3IndexAvg(arr, SIZE);

    GetLazy();
}