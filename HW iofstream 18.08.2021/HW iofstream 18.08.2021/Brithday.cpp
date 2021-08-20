#include "Headers.h"

BirthdayCollection::BirthdayCollection(string name)
{
	person_.name_ = name;

	collection_.push_back(person_);
	size_ = collection_.size();
}

BirthdayCollection::BirthdayCollection(string name, string date) 
{
	//перекладываем ответственность за корректный ввод на пользователя :)
	person_.name_ = name;
	person_.date_ = date;

	collection_.push_back(person_);
	size_ = collection_.size();
}

void BirthdayCollection::AddPerson(string name, string date)
{
	//перекладываем ответственность за корректный ввод на пользователя :)
	person_.name_ = name;
	person_.date_ = date;

	collection_.push_back(person_);
	size_ = collection_.size();

	SaveAndWriteToBin::SaveToBin(collection_);
}

string BirthdayCollection::SearchDateByName(string name)
{
	for (size_t i = 0; i < size_; i++)
	{
		if (collection_[i].name_ == name)
		{
			return collection_[i].date_;
		}
	}

	return "Not Found";
}

vector<string> BirthdayCollection::SearchNameByDate(string date)
{
	vector<string> collection;

	for (size_t i = 0; i < size_; i++)
	{
		if (collection_[i].date_ == date)
		{
			collection.push_back(collection_[i].name_);
		}
	}

	return collection;
}
