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

#ifndef __CONSOLELIB_H__
#define __CONSOLELIB_H__

#include <windows.h>

// Хендлы консоли
extern HANDLE hStdOut;
extern HANDLE hStdIn;

// Цвета
enum ConsoleColor
{
	Black         = 0,
	Blue          = 1,
	Green         = 2,
	Cyan          = 3,
	Red           = 4,
	Magenta       = 5,
	Brown         = 6,
	LightGray     = 7,
	DarkGray      = 8,
	LightBlue     = 9,
	LightGreen    = 10,
	LightCyan     = 11,
	LightRed      = 12,
	LightMagenta  = 13,
	Yellow        = 14,
	White         = 15
};

// Возвращает ширину буфера консоли
int GetConsoleBufferSizeX();
// Возвращает высоту буфера консоли
int GetConsoleBufferSizeY();
// Устанавливает нужный размер буфера консоли
void SetConsoleBufferSize(int x, int y);

// Возвращает ширину консоли
int GetConsoleSizeX();
// Возвращает высоту консоли
int GetConsoleSizeY();
// Устанавливает нужный размер консоли и буфера консоли
void SetConsoleSize(int x, int y);

// Очищает консоль
void ClearScreen();

// Показывает/прячет текстовый курсор.
// Возвращает предыдущий статус курсора.
bool ShowCursor(bool visible);

// Устанавливают текущий цвет символов и фона.
// Возвращают предыдущий текущий цвет символов и фона.
unsigned SetColor(ConsoleColor text, ConsoleColor background);
unsigned SetColor(unsigned colorAttr);

// Перемещает курсор в заданную позицию
void GotoXY(int x, int y);

// Выводит заданную строку в заданную позицию
void WriteStr(int x, int y, const char *str);

// Выводит заданный символ в заданную позицию
void WriteChar(int x, int y, char ch);

// Выводит заданный символ в заданном количестве, начиная с заданной позиции
void WriteChars(int x, int y, char ch, unsigned length);

// Меняет текстовые атрибуты указанного количества символов, начиная с заданной позиции
void ChangeTextAttr(int x, int y, ConsoleColor text, ConsoleColor background, unsigned length);

#endif // __CONSOLELIB_H__