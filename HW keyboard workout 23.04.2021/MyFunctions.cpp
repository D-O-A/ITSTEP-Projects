#include "ConsoleLib.h"
#include "MyHeader.h"
#include <iostream>
#include <ctime>
#include <conio.h>
using namespace std;

void WriteHorz(int x, int y, char ch, unsigned int length)
{
	for (size_t i = y; i < length; i++)
		WriteChar(x, i, ch);
}

void Invitation()
{
	cout << "Press SPACEBAR to start the game or Esc to quit..." << endl;
}

void DrawGrid()
{
	const unsigned char dash = 196;
	const unsigned char vertdash = 179;

	for (size_t i = 20; i <= 100; i += 20)
		WriteHorz(i, 0, vertdash, 47);

	ChangeTextAttr(0, 47, Red, Red, 120);
	WriteStr(0, 48, "Press Esc to quit...");
}

int GetSeed()
{
	int seed = rand() % 6 + 1;
	return seed;
}

int GetRandChar()
{
	int randchar = rand() % 26 + 97;
	return randchar;
}

void MoveCharDown(int x, char ch, int itercounter, int *plives, int *pspeed, int y)
{
	const int Spacebar = 32;
	const int Esc = 27;
	int counter = 0;
	int key = 0;
	int ypos = y;
	//флаг нужен для того, чтобы скорость увеличивалась только 1 раз за работу функции
	bool speedflag = true;
	
	while (counter < 46 && key != ch )
	{
		if (counter == 0)
		WriteChar(x, y, ch);

		ypos++;

		if (itercounter % 5 == 0 && (speedflag))
		{
			*pspeed -= 100;
			if (*pspeed <= 0)
				*pspeed = 40;
			speedflag = false;
		}

		Sleep(*pspeed);

		if (counter == 0)
			WriteChar(x, y, Spacebar);
		else if (counter > 0)
			WriteChar(x, ypos - 1, Spacebar);

		WriteChar(x, ypos, ch);
		counter++;

		while (_kbhit())
		{
			key = _getch();
			if (key == Esc)
				exit(0);
			else if (key == ch)
			{
				Beep(100, 200);
				WriteChar(x, ypos, Spacebar);
				break;
			}
		}

		if (counter == 46)
		{
			WriteChar(x, counter, Spacebar);
			Beep(200, 200);
			(*plives)--;
			if (*plives == 0)
				Loser();
		}
	}
}

void Loser()
{
	ClearScreen();
	while (true)
		cout << "LOSER";
}

void PrintLives(int *plives)
{
	GotoXY(40, 48);
	cout << "Lives - " << *plives;
}