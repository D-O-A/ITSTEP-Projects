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

	//Ќаписать логическую функцию, котора€ получает символьный параметр и возвращает true,
	//если указанный символ €вл€етс€ буквой верхнего регистра, и false в противном случае.

	setlocale(LC_ALL, "Russian");

	cout << "Enter a letter:\n";
	char letter, upper = 64, letterEnd = 122;
	cin >> letter;

	if (letter < upper || letter > 122)   // #костыли
		cout << "Ётот символ не €вл€етс€ буквой.\n";
	else if (UpperRegister(letter))
		cout << "Ёто символ €вл€етс€ буквой верхнего регистра.\n";
	else
		cout << "Ётот символ €вл€етс€ буквой нижнего регистра.\n";
}