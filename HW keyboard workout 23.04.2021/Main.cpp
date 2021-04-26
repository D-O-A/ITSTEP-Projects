#include <iostream>
#include <conio.h>
#include <windows.h>
#include "ConsoleLib.h"
#include "MyHeader.h"
using namespace std;

int main()
{
	cout << "2.\n\n";

	//Написать программу «Клавиатурный тренажер».

	srand((unsigned)time(0));

	SetConsoleBufferSize(120, 50);
	SetConsoleSize(120, 50);
	ShowCursor(false);

	const unsigned Spacebar = 32;
	const unsigned Esc = 27;
	const unsigned x1 = 10, x2 = 30, x3 = 50, x4 = 70, x5 = 90, x6 = 110;
	int lives = 3;
	int* plives = &lives;
	int itercounter = 0;
	int speed = 500;
	int* pspeed = &speed;

	Invitation();

	int key;

	do
	{
		key = _getch();
		if (key == Esc)
			exit(0);
	} while (key != Spacebar);

	ClearScreen();

	DrawGrid();

	do
	{
		itercounter++;
		PrintLives(plives);

		int seed = GetSeed();
		int randchar = GetRandChar();

		switch (seed)
		{
		case 1:
			MoveCharDown(x1, randchar, itercounter, &lives, &speed);
			break;
		case 2:
			MoveCharDown(x2, randchar, itercounter, &lives, &speed);
			break;
		case 3:
			MoveCharDown(x3, randchar, itercounter, &lives, &speed);
			break;
		case 4:
			MoveCharDown(x4, randchar, itercounter, &lives, &speed);
			break;
		case 5:
			MoveCharDown(x5, randchar, itercounter, &lives, &speed);
			break;
		case 6:
			MoveCharDown(x6, randchar, itercounter, &lives, &speed);
			break;
		}
	} while (true);
}