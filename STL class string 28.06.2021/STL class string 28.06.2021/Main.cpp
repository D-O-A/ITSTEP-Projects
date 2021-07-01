#include <iostream>
#include <string>
using namespace std;

int main()
{

	//1
	cout << "enter string:";

	string str;
	getline(cin, str);

	cout << "Enter word:";

	string str2;
	getline(cin, str2);

	int pos = -1;
	int counter = 0;

	do
	{
		pos = str.find(str2, pos + 1);
		counter++;

	} while (pos != string::npos);

	cout << "Word repeats " << counter - 1 << " times" << endl;

	cout << "Enter phone number:";
	string str3;
	getline(cin, str3);

	//2
	//?
	if (str3.find_first_not_of("123456789+"))
	{
		cout << "you entered wrong number!";
	}


	//3
	pos = -1;
	do
	{
		pos = str.find(str2, pos + 1);
		str.erase(pos + 1, str2.length());

	} while (pos != string::npos);

	cout << str << endl;




}