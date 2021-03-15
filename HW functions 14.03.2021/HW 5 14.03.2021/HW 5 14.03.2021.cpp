#include <iostream>
using namespace std;

bool UpperRegister(char symbol)
{
	char lower = 97, upper = 64;   // начало верхних и нижних регистров
	if (symbol > upper && symbol < lower)
		return true;
	else
		return false;
}

int main()
{
	cout << "5.\n\n";
	//Написать логическую функцию, которая получает символьный параметр и возвращает true,
	//если указанный символ является буквой верхнего регистра, и false в противном случае.

	setlocale(LC_ALL, "Russian");

	char letter, upper = 64, letterEnd = 122;

	cout << "Enter a letter:\n";
	cin >> letter;

	if (letter < upper || letter > 122)   // #костыли
		cout << "Этот символ не является буквой.\n";
	else if (UpperRegister(letter))
		cout << "Это символ является буквой верхнего регистра.\n";
	else
		cout << "Этот символ является буквой нижнего регистра.\n";
}