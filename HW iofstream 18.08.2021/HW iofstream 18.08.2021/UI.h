#pragma once
#include "Headers.h"

enum class Choice
{
	PRINT_FROM_FILE = 1,
	ADD_PERSON,
	SEARCH_DATE_BY_NAME,
	SEARCH_NAME_BY_DATE,
	CLEAR_SCREEN,
	EXIT
};

class UI
{
public:

	static Choice PrintMenu();
	static string EnterName();
	static string EnterDate();
	static string EnterNameToSearch();
	static string EnterDateToSearch();

	static void PrintDateByNameSearchResult(string result);
	static void PrintNameByDateSearchResults(vector<string> result);

};