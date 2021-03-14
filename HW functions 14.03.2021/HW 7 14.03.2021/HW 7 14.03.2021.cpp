#include <iostream>
using namespace std;

bool SymbolCheck(char symbol)
{
	char numberStart = 47, numberEnd = 58;
	if (symbol > numberStart && symbol < numberEnd)
		return true;
	else
		return false;
}

int main()
{
	cout << "7.\n\n";

	//Написать логическую функцию, которая получает символьный параметр и возвращает true, 
	//если указанный символ является цифрой, и false в противном случае.

	setlocale(LC_ALL, "Russian");

	cout << "Enter a symbol:\n";
	char symbol;
	cin >> symbol;

	if (SymbolCheck(symbol))
		cout << "Это символ является цифрой.\n";
	else
		cout << "Этот символ не является цифрой.\n";
}