#include <iostream>
using namespace std;

bool LetterAndSymbolCheck(char symbol)
{
	char letterEnd2 = 123, letterEnd1 = 91, letterStart1 = 64, letterStart2 = 96, numberStart = 47, numberEnd = 58;;
	if ((symbol > letterStart1 && symbol < letterEnd1) 
		|| (symbol > letterStart2 && symbol < letterEnd2) 
		|| (symbol > numberStart && symbol < numberEnd))
		return true;
	else
		return false;
}

int main()
{
	cout << "8.\n\n";

	//Написать логическую функцию, которая получает символьный параметр и возвращает true, 
	//если указанный символ является буквой любого регистра или цифрой, и false в противном случае.

	setlocale(LC_ALL, "Russian");

	cout << "Enter a symbol:\n";
	char letter;
	cin >> letter;

	if (LetterAndSymbolCheck(letter))
		cout << "Это символ является буквой или цифрой.\n";
	else
		cout << "Этот символ не является буквой или цифрой.\n";
}