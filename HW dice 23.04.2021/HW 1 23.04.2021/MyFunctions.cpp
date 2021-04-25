#include "ConsoleLib.h"
#include <iostream>
using namespace std;

void WriteHorz(int x, int y, char ch, unsigned int length)
{
	for (size_t i = y; i < length; i++)
		WriteChar(x, i, ch);
}

void WriteCorners(int x, int y)
{
	const unsigned char topleftcorner = 218;
	const unsigned char toprightcorner = 191;
	const unsigned char botleftcorner = 192;
	const unsigned char botrightcorner = 217;

	WriteChar(x, y, topleftcorner);
	WriteChar(x + 14, y, toprightcorner);
	WriteChar(x, y + 6, botleftcorner);
	WriteChar(x + 14, y + 6, botrightcorner);
}

void DrawDie1(int x, int y)
{
	const unsigned char dash = 196;
	const unsigned char vertdash = 179;
	const unsigned char topleftcorner = 218;
	const unsigned char toprightcorner = 191;
	const unsigned char botleftcorner = 192;
	const unsigned char botrightcorner = 217;
	const int vertlength = x + 11;
	const int horzlength = y + 6;

	//моя функция для рисования углов
	WriteCorners(x, y);
	WriteChars(x + 1, y, dash, vertlength);
	WriteChars(x + 1, y + 6, dash, vertlength);
	//моя функция для рисования "вниз"
	WriteHorz(x, y + 1, vertdash, horzlength);
	WriteHorz(x + 14, y + 1, vertdash, horzlength);
}

void DrawDie2(int x, int y)
{
	const unsigned char dash = 196;
	const unsigned char vertdash = 179;
	const unsigned char topleftcorner = 218;
	const unsigned char toprightcorner = 191;
	const unsigned char botleftcorner = 192;
	const unsigned char botrightcorner = 217;
	const int vertlength = x + 11;
	const int horzlength = y + 6;

	//моя функция для рисования углов
	WriteCorners(x + 17, y);
	WriteChars(x + 18, y, dash, vertlength);
	WriteChars(x + 18, y + 6, dash, vertlength);
	//моя функция для рисования "вниз"
	WriteHorz(x + 17, y + 1, vertdash, horzlength);
	WriteHorz(x + 31, y + 1, vertdash, horzlength);
}

void Roll2(int x, int y)
{
	const unsigned char smile = 2;

	//1L
	WriteChar(x + 7, y + 3, smile);
	//1R
	WriteChar(x + 24, y + 3, smile);
}

void Roll3(int x, int y)
{
	const unsigned char smile = 2;

	//2L
	WriteChar(x + 11, y + 1, smile);
	WriteChar(x + 3, y + 5, smile);
	//1R
	WriteChar(x + 24, y + 3, smile);
}

void Roll4(int x, int y)
{
	const unsigned char smile = 2;

	//2L
	WriteChar(x + 11, y + 1, smile);
	WriteChar(x + 3, y + 5, smile);
	//2R
	WriteChar(x + 28, y + 1, smile);
	WriteChar(x + 20, y + 5, smile);
}

void Roll5(int x, int y)
{
	const unsigned char smile = 2;

	//2L
	WriteChar(x + 11, y + 1, smile);
	WriteChar(x + 3, y + 5, smile);
	//3R
	WriteChar(x + 24, y + 3, smile);
	WriteChar(x + 28, y + 1, smile);
	WriteChar(x + 20, y + 5, smile);
}

void Roll6(int x, int y)
{
	const unsigned char smile = 2;

	//4L
	WriteChar(x + 3, y + 1, smile);
	WriteChar(x + 11, y + 1, smile);
	WriteChar(x + 3, y + 5, smile);
	WriteChar(x + 11, y + 5, smile);
	//2R
	WriteChar(x + 28, y + 1, smile);
	WriteChar(x + 20, y + 5, smile);
}

void Roll7(int x, int y)
{
	const unsigned char smile = 2;

	//5L
	WriteChar(x + 3, y + 1, smile);
	WriteChar(x + 11, y + 1, smile);
	WriteChar(x + 3, y + 5, smile);
	WriteChar(x + 11, y + 5, smile);
	WriteChar(x + 7, y + 3, smile);
	//2R
	WriteChar(x + 28, y + 1, smile);
	WriteChar(x + 20, y + 5, smile);
}

void Roll8(int x, int y)
{
	const unsigned char smile = 2;

	//4L
	WriteChar(x + 3, y + 1, smile);
	WriteChar(x + 11, y + 1, smile);
	WriteChar(x + 3, y + 5, smile);
	WriteChar(x + 11, y + 5, smile);
	//4R
	WriteChar(x + 20, y + 1, smile);
	WriteChar(x + 28, y + 1, smile);
	WriteChar(x + 20, y + 5, smile);
	WriteChar(x + 28, y + 5, smile);
}

void Roll9(int x, int y)
{
	const unsigned char smile = 2;

	//6R
	WriteChar(x + 20, y + 3, smile);
	WriteChar(x + 28, y + 3, smile);
	WriteChar(x + 20, y + 1, smile);
	WriteChar(x + 28, y + 1, smile);
	WriteChar(x + 20, y + 5, smile);
	WriteChar(x + 28, y + 5, smile);
	//3L
	WriteChar(x + 7, y + 3, smile);
	WriteChar(x + 11, y + 1, smile);
	WriteChar(x + 3, y + 5, smile);
}

void Roll10(int x, int y)
{
	const unsigned char smile = 2;

	//5L
	WriteChar(x + 3, y + 1, smile);
	WriteChar(x + 11, y + 1, smile);
	WriteChar(x + 3, y + 5, smile);
	WriteChar(x + 11, y + 5, smile);
	WriteChar(x + 7, y + 3, smile);
	//5R
	WriteChar(x + 20, y + 1, smile);
	WriteChar(x + 28, y + 1, smile);
	WriteChar(x + 20, y + 5, smile);
	WriteChar(x + 28, y + 5, smile);
	WriteChar(x + 24, y + 3, smile);
}

void Roll11(int x, int y)
{
	const unsigned char smile = 2;

	//6L
	WriteChar(x + 2, y + 3, smile);
	WriteChar(x + 11, y + 3, smile);
	WriteChar(x + 2, y + 1, smile);
	WriteChar(x + 11, y + 1, smile);
	WriteChar(x + 2, y + 5, smile);
	WriteChar(x + 11, y + 5, smile);
	//5R
	WriteChar(x + 20, y + 1, smile);
	WriteChar(x + 28, y + 1, smile);
	WriteChar(x + 20, y + 5, smile);
	WriteChar(x + 28, y + 5, smile);
	WriteChar(x + 24, y + 3, smile);
}

void Roll12(int x, int y)
{
	const unsigned char smile = 2;

	//6L
	WriteChar(x + 2, y + 3, smile);
	WriteChar(x + 11, y + 3, smile);
	WriteChar(x + 2, y + 1, smile);
	WriteChar(x + 11, y + 1, smile);
	WriteChar(x + 2, y + 5, smile);
	WriteChar(x + 11, y + 5, smile);
	//6R
	WriteChar(x + 20, y + 3, smile);
	WriteChar(x + 28, y + 3, smile);
	WriteChar(x + 20, y + 1, smile);
	WriteChar(x + 28, y + 1, smile);
	WriteChar(x + 20, y + 5, smile);
	WriteChar(x + 28, y + 5, smile);
}

void PrintMyTurn()
{
	cout << "Now it's my turn to roll..." << endl;
	Sleep(1000);
}

void Invitation()
{
	cout << "Press SPACEBAR to roll the dice or Esc to quit..." << endl;
}

int GetRoll()
{
	unsigned roll = rand() % 11 + 2;
	return roll;
}

void PrintResult(unsigned roll1, unsigned roll2)
{
	cout << "You rolled " << roll1 << " and I rolled " << roll2 << endl
		 << (roll1 > roll2 ? "You won!" : "I won! ;)") << endl;
}

void PressEnter()
{
	cout << "Press Spacebar to play again or Esc to quit...";
}