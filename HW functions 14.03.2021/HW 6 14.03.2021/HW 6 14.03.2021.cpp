#include <iostream>
using namespace std;

bool UpperRegister(char symbol)
{
	char letterEnd2 = 123, letterEnd1 = 91 , letterStart1 = 64, letterStart2 = 96;   
	if ((symbol > letterStart1 && symbol < letterEnd1) || (symbol > letterStart2 && symbol < letterEnd2))
		return true;
	else
		return false;
}

int main()
{
	cout << "6.\n\n";

	//Написать логическую функцию, которая получает символьный параметр и возвращает true,
	//если указанный символ является буквой любого регистра, и false в противном случае.

	setlocale(LC_ALL, "Russian");

	cout << "Enter a letter:\n";
	char letter;
	cin >> letter;

	if (UpperRegister(letter))
		cout << "Это символ является буквой.\n";
	else
		cout << "Этот символ не является буквой.\n";
}