#pragma once
#include "Headers.h"

class Person
{
public:
	Person() = default;
	Person(string name, string date) : name_(name), date_(date)
	{
	}

	string name_ = "undefined";
	string date_ = "undefined";
};

class BirthdayCollection
{
	friend class SaveAndWriteToBin;

public:

	BirthdayCollection() = default;
	BirthdayCollection(string name);
	BirthdayCollection(string name, string date);

	void AddPerson(string name, string date);

	string SearchDateByName(string name);
	vector<string> SearchNameByDate(string date);

private:

	Person person_;

	vector<Person> collection_;
	size_t size_ = 0;
};

