#include <iostream>
using namespace std;

void PrintSquare(int h = 10, int w = 10)
{
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
			cout << '*';
		cout << endl;
	}
	cout << endl;
}

int main()
{
	cout << "2.\n\n";

	//Написать функцию, которая рисует заполненный прямоугольник, состоящий из символов '*'.
	//Высота и ширина прямоугольника задается входными параметрами. Значения по умолчанию для этих параметров: 10x10.

	PrintSquare();
}