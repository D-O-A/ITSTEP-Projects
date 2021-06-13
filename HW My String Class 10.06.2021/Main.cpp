#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
	MyStringClass my_string;

	//проверка конструктора
	MyStringClass my_string1("Test my_string1");
	my_string1.PrintStr();

	cout << endl;

	char str[100];

	cout << "Enter string:";
	cin.getline(str, 100);

	cout << endl;

	my_string.Assign(str);

	my_string.Append("Write");

	my_string.PrintStr();

	cout << endl << endl;

	my_string.Insert(10, "HERE");

	my_string.PrintStr();

	cout << endl << endl;

	my_string.Remove(5, 10);

	my_string.PrintStr();

	cout << endl << endl;

}