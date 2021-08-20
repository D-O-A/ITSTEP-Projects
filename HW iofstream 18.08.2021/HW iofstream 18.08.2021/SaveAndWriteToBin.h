#pragma once
#include "Headers.h"
class SaveAndWriteToBin 
{
public:

	static void SaveToBin(BirthdayCollection& birthday);
	static void SaveToBin(vector<Person> collection);
	static void ReadFromBin(BirthdayCollection& birthday);
	static void PrintFromBin(BirthdayCollection& birthday);
};