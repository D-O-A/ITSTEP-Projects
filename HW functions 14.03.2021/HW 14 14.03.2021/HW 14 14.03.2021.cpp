#include <iostream>
using namespace std;

void Square(unsigned width)   //квадрат
{
	for (int y = 1; y <= width; y++)  
	{
		for (int x = 1; x <= width; x++)
		{
			if (y == 1 || y == width || x == 1 || x == width)
				cout << '*';
			else
				cout << ' ';
		}
		cout << endl;
	}

	cout << endl;

	for (int y = 1; y <= width; y++)
	{
		for (int x = 1; x <= width; x++)
			cout << '*';
		cout << endl;
	}
	cout << endl;
}

void Rectangle(unsigned height, unsigned width)   // прямоугольник
{
	for (int y = 1; y <= height; y++)
	{
		for (int x = 1; x <= width; x++)
		{
			if (y == 1 || y == height || x == 1 || x == width)
				cout << '*';
			else
				cout << ' ';
		}
		cout << endl;
	}

	cout << endl;

	for (int y = 1; y <= height; y++)
	{
		for (int x = 1; x <= width; x++)
			cout << '*';
		cout << endl;
	}
	cout << endl;
}

void UAflag(unsigned width)   // флаг украины
{
	unsigned height = width / 3;
	for (int y = 1; y <= height; y++)
	{
		for (int x = 1; x <= width; x++)
		{
			if (y == 1 || y == height || x == 1 || x == width || y == height / 2 + 1)  
				cout << '*';
			else
				cout << ' ';
		}
		cout << endl;
	}
	
	cout << endl;

	for (int y = 1; y <= height; y++)
	{
		for (int x = 1; x <= width; x++)
		{
			if (y == 1 || y == height || x == 1 || x == width || y == height / 2 + 1 || y > height / 2 + 1)
				cout << '*';
			else
				cout << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void Triangle(int height)   // равнобедренный треугольник
{
	for (int y = 0; y <= height; y++) 
	{
		for (int x = 0; x <= height; x++)
		{
			if (y == height || y == -2 * x + height || y == 2 * x + -height)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}

	cout << endl;

	for (int y = 0; y <= height; y++)
	{
		for (int x = 0; x <= height; x++)
		{
			if (y == height || y == -2 * x + height || y == 2 * x + -height)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
}

void Diamond(int height)   // ромб
{
	for (int y = 0; y <= height; y++)
	{
		for (int x = 0; x <= height; x++)
		{
			if (y == -1 * x + height / 2 || y == x + -height / 2 || y == x + height / 2 || y == -1 * x + height + height / 2)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}

	cout << endl;

	for (int y = 0; y <= height; y++) 
	{
		for (int x = 0; x <= height; x++)
		{
			if (y == -1 * x + height / 2 || y == x + -height / 2 || y == x + height / 2 || y == -1 * x + height + height / 2)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
}

void Tree(int branch, int height)
{
	int n = height; // я кончусь везде исправлять n на height
	for (int y = 0; y <= height; y++) // елка
	{
		for (int x = 0; x <= height; x++) // цикл верхушки
		{
			if (y == -x + height / 2 || y == x + -height / 2 || y == height / 2 && x <= height / 3 || y == height / 2 && x >= height / 2 + height / 5)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;

		if (y == n / 2) // проверка на позицию курсора

			for (int b = 0; b <= branch - 2; b++) // цикл веточек
			{
				for (int y = 0; y <= height / 3; y++)
				{
					for (int x = 0; x <= height; x++)
					{
						if (y == -x + height / 3 || y == x + -n / 2 + -n / 5 || y == n / 2 - n / 5 && x <= n / 3
							|| y == n / 2 - n / 5 && x >= n / 2 + n / 5)
							cout << "*";
						else
							cout << " ";
					}
					cout << endl;
				}
			}

		if (y == n / 2) // проверка на позицию курсора

			for (int y = 0; y <= n / 2; y++)  // цикл пенька
			{
				for (int x = 0; x <= n; x++)
				{
					if (x == n / 3 && y <= n / 5 || y == n / 5 && x >= n / 3 && x <= n / 2 + n / 5 || x == n / 2 + n / 5 && y <= n / 5)
						cout << "*";
					else
						cout << " ";
				}
				cout << endl;
			}

		if (y == n / 2) // чтобы меньше выводило пустых строк после пенька #оптимизация
			break;
	}

	cout << endl;


	for (int y = 0; y <= height; y++) // елка
	{
		for (int x = 0; x <= height; x++) // цикл верхушки
		{
			if (y == -x + height / 2 || y == x + -height / 2 || y == height / 2 && x <= height / 3 || y == height / 2 && x >= height / 2 + height / 5)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;

		if (y == n / 2) // проверка на позицию курсора

			for (int b = 0; b <= branch - 2; b++) // цикл веточек
			{
				for (int y = 0; y <= height / 3; y++)
				{
					for (int x = 0; x <= height; x++)
					{
						if (y == -x + height / 3 || y == x + -n / 2 + -n / 5 || y == n / 2 - n / 5 && x <= n / 3
							|| y == n / 2 - n / 5 && x >= n / 2 + n / 5)
							cout << "*";
						else
							cout << " ";
					}
					cout << endl;
				}
			}

		if (y == n / 2) // проверка на позицию курсора

			for (int y = 0; y <= n / 2; y++)  // цикл пенька
			{
				for (int x = 0; x <= n; x++)
				{
					if (x == n / 3 && y <= n / 5 || y == n / 5 && x >= n / 3 && x <= n / 2 + n / 5 || x == n / 2 + n / 5 && y <= n / 5)
						cout << "*";
					else
						cout << " ";
				}
				cout << endl;
			}

		if (y == n / 2) // чтобы меньше выводило пустых строк после пенька #оптимизация
			break;
	}
}

int main()
{
	cout << "14.\n\n";

	//Написать функции, выводящие на экран следующие фигуры, состоящие из символа '*' (разнести ранее написанный код по функциям):
	//•	квадрат(пользователь вводит длину стороны);
	//•	прямоугольник(пользователь вводит ширину и высоту);
	//•	флаг Украины(пользователь вводит ширину, высота равна трети ширины);
	//•	равнобедренный треугольник(пользователь вводит высоту);
	//•	ромб(пользователь вводит диагональ);
	//•	ёлочка(пользователь вводит высоту одной ветки и их количество).
	//Реализовать 2 варианта вывода каждой фигуры – заполненный и незаполненный.

	setlocale(LC_ALL, "Russian");
	unsigned width, height, branch;
	cout << "Введите длину:"; cin >> width;
	Square(width);
	cout << "Введите высоту и ширину:\n";
	cin >> height >> width;
	Rectangle(height, width);
	cout << "Введите ширину:"; cin >> width;   // рекомендую вводить 15
	UAflag(width);
	cout << "Введите высоту:"; cin >> height;
	Triangle(height);
	cout << "Введите диагональ:"; cin >> height;
	Diamond(height);
	cout << "Введите количество веток и высоту:\n";
	cin >> branch >> height;
	Tree(branch, height);
}