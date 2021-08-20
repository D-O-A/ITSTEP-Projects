#include "Headers.h"

Choice UI::PrintMenu()
{
	unsigned choice;

	do
	{
		cout << "1. Print from file\n"
			<< "2. Add person\n"
			<< "3. Search by name\n"
			<< "4. Search by date\n"
			<< "5. Clear screen\n"
			<< "6. Exit" << endl;

		cin >> choice;
		cin.ignore();

		if (choice < 1 || choice > 6)
		{
			cout << "Wrong input, try again!" << endl;
		}
	}
	while (choice < 1 || choice > 6);

	return (Choice)choice;
}

string UI::EnterName()
{
	//перекладываем ответственность за корректный ввод на пользователя :)
	string name;

	cout << "Enter name:" << endl;
	getline(cin, name);

	return name;
}

string UI::EnterDate()
{
	//перекладываем ответственность за корректный ввод на пользователя :)
	string date;

	cout << "Enter date:" << endl;
	getline(cin, date);

	return date;
}

string UI::EnterNameToSearch()
{
	//перекладываем ответственность за корректный ввод на пользователя :)
	string name;

	cout << "Enter name to search the date:";
	getline(cin, name);

	return name;
}

string UI::EnterDateToSearch()
{
	//перекладываем ответственность за корректный ввод на пользователя :)
	string date;

	cout << "Enter date to search name:";
	getline(cin, date);

	return date;
}

void UI::PrintDateByNameSearchResult(string result)
{
	cout << result << endl;
}

void UI::PrintNameByDateSearchResults(vector<string> result)
{
	size_t size = result.size();

	if (size == 0)
	{
		cout << "Not found" << endl;
	}

	for (size_t i = 0; i < size; i++)
	{
		cout << result[i] << endl;
	}
}