/*********************************************************************/
/*                                                                   */
/*    ConsoleLib [Release 3.0.0]                                     */
/*    Библиотека функций-оберток для работы с консолью               */
/*                                                                   */
/*    Copyright (с) 2006-2019, Дмитрий Барабаш                       */
/*                                                                   */
/*    E-mail:   dmitry@barabash.com                                  */
/*    Web:      http://itstep.barabash.com                           */
/*                                                                   */
/*********************************************************************/

#include <iostream>
using namespace std;

#include <windows.h>
#include "ConsoleLib.h"


// Хендлы консоли
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hStdIn = GetStdHandle(STD_INPUT_HANDLE);

// Возвращает ширину буфера консоли
int GetConsoleBufferSizeX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hStdOut, &csbi);
	return csbi.dwSize.X;
}

// Возвращает высоту буфера консоли
int GetConsoleBufferSizeY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hStdOut, &csbi);
	return csbi.dwSize.Y;
}

// Устанавливает нужный размер буфера консоли
void SetConsoleBufferSize(int x, int y)
{
	COORD conSize = { (SHORT)x, (SHORT)y };
	SetConsoleScreenBufferSize(hStdOut, conSize);
}

// Возвращает ширину консоли
int GetConsoleSizeX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hStdOut, &csbi);
	return csbi.srWindow.Right + 1;
}

// Возвращает высоту консоли
int GetConsoleSizeY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hStdOut, &csbi);
	return csbi.srWindow.Bottom + 1;
}

// Устанавливает нужный размер консоли
void SetConsoleSize(int x, int y)
{
	SMALL_RECT rect = { 0, 0, (SHORT)(x - 1), (SHORT)(y - 1) };
	SetConsoleWindowInfo(hStdOut, TRUE, &rect);
}

// Очищает консоль
void ClearScreen()
{
   COORD coordScreen = { 0, 0 };
   DWORD cCharsWritten;
   CONSOLE_SCREEN_BUFFER_INFO csbi;
   DWORD dwConSize;
   DWORD dwConAttr;

   // Получаем общее количество символов консоли и текущий цвет консоли
   GetConsoleScreenBufferInfo(hStdOut, &csbi);
   dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
   dwConAttr = csbi.wAttributes;

   // Заполняем консоль пробелами
   FillConsoleOutputCharacter(hStdOut, ' ', dwConSize, coordScreen, &cCharsWritten);
   // Заполняем консоль текущим цветом консоли
   FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);

   // Устанавливаем курсор в левый верхний угол консоли
   SetConsoleCursorPosition(hStdOut, coordScreen);
}

// Показывает/прячет текстовый курсор.
// Возвращает предыдущий статус курсора.
bool ShowCursor(bool visible)
{
	CONSOLE_CURSOR_INFO cci = { sizeof(cci) };
	GetConsoleCursorInfo(hStdOut, &cci);

	bool prevVisible = cci.bVisible;

	cci.bVisible = visible;
	SetConsoleCursorInfo(hStdOut, &cci);

	return prevVisible;
}

// Устанавливает текущий цвет символов и фона.
// Возвращает предыдущий текущий цвет символов и фона.
unsigned SetColor(unsigned colorAttr)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi = { sizeof(csbi) };
    GetConsoleScreenBufferInfo(hStdOut, &csbi);

    SetConsoleTextAttribute(hStdOut, (WORD)colorAttr);

    return csbi.wAttributes;
}

// Устанавливает текущий цвет символов и фона.
// Возвращает предыдущий текущий цвет символов и фона.
unsigned SetColor(ConsoleColor text, ConsoleColor background)
{
    return SetColor((WORD)((background << 4) | text));
}

// Перемещает курсор в заданную позицию
void GotoXY(int x, int y)
{
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hStdOut, coord);
}

// Выводит заданную строку в заданную позицию
void WriteStr(int x, int y, const char *str)
{
    GotoXY(x, y);
    cout << str << flush;
}

// Выводит заданный символ в заданную позицию
void WriteChar(int x, int y, char ch)
{
	GotoXY(x, y);
	cout << ch;
}

// Выводит заданный символ в заданном количестве, начиная с заданной позиции
void WriteChars(int x, int y, char ch, unsigned length)
{
	GotoXY(x, y);
	for (unsigned i = 0; i < length; i++)
		cout << ch;
}

// Меняет текстовые атрибуты указанного количества символов, начиная с заданной позиции
void ChangeTextAttr(int x, int y, ConsoleColor text, ConsoleColor background, unsigned length)
{
	COORD coord = { (SHORT)x, (SHORT)y };
	DWORD dwDummy;
	FillConsoleOutputAttribute(hStdOut, (WORD)((background << 4) | text), length, coord, &dwDummy);
}