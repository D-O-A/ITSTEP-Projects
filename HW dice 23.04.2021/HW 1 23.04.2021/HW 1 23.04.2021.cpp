#include <iostream>
#include <ctime>;
#include <conio.h>
#include <windows.h>
#include "ConsoleLib.h"
#include "MyHeader.h"
using namespace std;

int main()
{
	cout << "1.\n\n";

	//Написать программу «Игра в кости».

	srand((unsigned)time(0));

	const int Spacebar = 32;
	const int Esc = 27;

	const int x1 = 2;
	const int y1 = 3;
	 
	const int x2 = 2;
	const int y2 = 11;

	SetConsoleSize(52, 24);
	ShowCursor(false);

	int key;

	do
	{
		Invitation();
		do
		{
	 		key = _getch();
			if (key == Esc)
				exit(0);
		} while (key != Spacebar);

		unsigned roll1 = GetRoll();

		DrawDie1(x1, y1);
		DrawDie2(x1, y1);

		switch (roll1)
		{
		case 2:
			Roll2(x1, y1);
			break;
		case 3:
			Roll3(x1, y1);
			break;
		case 4:
			Roll4(x1, y1);
			break;
		case 5:
			Roll5(x1, y1);
			break;
		case 6:
			Roll6(x1, y1);
			break;
		case 7:
			Roll7(x1, y1);
			break;
		case 8:
			Roll8(x1, y1);
			break;
		case 9:
			Roll9(x1, y1);
			break;
		case 10:
			Roll10(x1, y1);
			break;
		case 11:
			Roll11(x1, y1);
			break;
		case 12:
			Roll12(x1, y1);
			break;
		}

		GotoXY(0, 10);

		PrintMyTurn();

		unsigned roll2 = GetRoll();

		DrawDie1(x2, y2);
		DrawDie2(x2, y2);

		switch (roll2)
		{
		case 2:
			Roll2(x2, y2);
			break;
		case 3:
			Roll3(x2, y2);
			break;
		case 4:
			Roll4(x2, y2);
			break;
		case 5:
			Roll5(x2, y2);
			break;
		case 6:
			Roll6(x2, y2);
			break;
		case 7:
			Roll7(x2, y2);
			break;
		case 8:
			Roll8(x2, y2);
			break;
		case 9:
			Roll9(x2, y2);
			break;
		case 10:
			Roll10(x2, y2);
			break;
		case 11:
			Roll11(x2, y2);
			break;
		case 12:
			Roll12(x2, y2);
			break;
		}

		GotoXY(0, 18);

		PrintResult(roll1, roll2);

		PressEnter();

		do
		{
			key = _getch();
			if (key == Esc)
				exit(0);
		} while (key != Spacebar);

		ClearScreen();
	} while (true);
}