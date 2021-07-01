#pragma once
#include <iostream>
using namespace std;

template <typename T>
void PrintArr(T* arr, const size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}

template <typename T>
void InputElements(T* arr, const size_t size)
{
	cout << "Enter number:\n";

	for (size_t i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
}

//?
//template<>
//void InputElements<char*>(char* arr,)
//{
//	cout << "Enter number:\n";
//
//	for (size_t i = 0; i < size; i++)
//	{
//		cin >> arr[i];
//	}
//}

template <typename T>
T GetMax(T* arr, const size_t size)
{
	T max = arr[0];

	for (size_t i = 1; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	return max;
}

template <typename T>
T GetMin(T* arr, const size_t size)
{
	T min = arr[0];

	for (size_t i = 1; i < size; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}

	return min;
}

template <typename T>
void SortArr(T* arr, const size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = size - 1; j > i; j--)
		{
			if (arr[j - 1] > arr[j])
			{
				T temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

template <typename T>
T SearchKeyElement(T* arr, const size_t size)
{
	T key;

	cout << "Enter key:";
	cin >> key;

	for (size_t i = 0; i < size; i++)
	{
		if (key == arr[i])
		{
			return i;
		}
	}

	// не придумал что нам вернуть если не нашли элемент
	throw exception("Not found!");
}

template <typename T>
void PrintElement(T element)
{
	cout << element;
}