#include "Headers.h"

int main()
{
	try
	{
		BirthdayCollection birthday;
		SaveAndWriteToBin::ReadFromBin(birthday);

		do
		{
			switch (UI::PrintMenu())
			{
			case Choice::PRINT_FROM_FILE:
				SaveAndWriteToBin::PrintFromBin(birthday);
				break;
			case Choice::ADD_PERSON:
				birthday.AddPerson(UI::EnterName(), UI::EnterDate());
				break;
			case Choice::SEARCH_DATE_BY_NAME:
				UI::PrintDateByNameSearchResult(birthday.SearchDateByName(UI::EnterNameToSearch())); //синтаксис огонь
				break;
			case Choice::SEARCH_NAME_BY_DATE:
				UI::PrintNameByDateSearchResults(birthday.SearchNameByDate(UI::EnterDateToSearch()));
				break;
			case Choice::CLEAR_SCREEN:
				system("cls");
				break;
			case Choice::EXIT:
				exit(0);
				break;
			}

		} while (true);

	}
	catch (exception& ex)
	{
		cout << ex.what();
	}
}