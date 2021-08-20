#include "Headers.h"

void SaveAndWriteToBin::SaveToBin(BirthdayCollection& birthday)
{
	ofstream fout("file.bin", ios::binary | ios::app);

	if (!fout.is_open())
	{
		throw exception("File not opened!");
	}

	if (birthday.size_ == 0)
	{
		throw exception("Collection is empty!");
	}

	const char* name;
	const char* date;

	size_t sizeOfNameStr;
	size_t sizeOfDateStr;

	for (size_t i = 0; i < birthday.size_; i++)
	{
		name = birthday.collection_[i].name_.c_str();
		date = birthday.collection_[i].date_.c_str();

		sizeOfNameStr = birthday.collection_[i].name_.size() + 1;
		sizeOfDateStr = birthday.collection_[i].date_.size() + 1;

		fout.write((char*)&sizeOfNameStr, sizeof(size_t));
		fout.write(name, sizeOfNameStr);

		fout.write((char*)&sizeOfDateStr, sizeof(size_t));
		fout.write(date, sizeOfDateStr);
	}
}

void SaveAndWriteToBin::SaveToBin(vector<Person> collection)
{
	ofstream fout("file.bin", ios::binary | ios::app);

	if (!fout.is_open())
	{
		throw exception("File not opened!");
	}

	if (collection.size() == 0)
	{
		throw exception("Collection is empty!");
	}

	const char* name;
	const char* date;

	size_t sizeOfNameStr;
	size_t sizeOfDateStr;

	for (size_t i = 0; i < collection.size(); i++)
	{
		name = collection[i].name_.c_str();
		date = collection[i].date_.c_str();

		sizeOfNameStr = collection[i].name_.size() + 1;
		sizeOfDateStr = collection[i].date_.size() + 1;

		fout.write((char*)&sizeOfNameStr, sizeof(size_t));
		fout.write(name, sizeOfNameStr);

		fout.write((char*)&sizeOfDateStr, sizeof(size_t));
		fout.write(date, sizeOfDateStr);
	}
}

void SaveAndWriteToBin::ReadFromBin(BirthdayCollection& birthday)
{
	ifstream fin("file.bin", ios::binary | ios::in);

	if (!fin.is_open())
	{
		cerr << "File not opened!" << endl;
		return;
	}

	fin.exceptions(ios::eofbit);

	while (!fin.eof())
	{
		try 
		{
			size_t sizeOfNameStr;
			size_t sizeOfDateStr;

			char* name = nullptr;
			char* date = nullptr;

			fin.read((char*)&sizeOfNameStr, sizeof(size_t));
			name = new char[sizeOfNameStr];
			fin.read(name, sizeOfNameStr);

			fin.read((char*)&sizeOfDateStr, sizeof(size_t));
			date = new char[sizeOfDateStr];
			fin.read(date, sizeOfDateStr);

			birthday.person_.name_ = string(name);
			birthday.person_.date_ = string(date);

			birthday.collection_.push_back(birthday.person_);

			if (name != nullptr && date != nullptr)
			{
				delete[] name;
				delete[] date;
			}

		}
		catch (ios::failure& ex)
		{
			break;
		}
	}

	birthday.size_ = birthday.collection_.size();
}

void SaveAndWriteToBin::PrintFromBin(BirthdayCollection& birthday)
{

	ifstream fin("file.bin", ios::binary | ios::in);

	if (!fin.is_open())
	{
		cerr << "File not opened!" << endl;
		return;
	}

	while (!fin.eof())
	{
		size_t sizeOfNameStr;
		size_t sizeOfDateStr;

		char* name = nullptr;
		char* date = nullptr;

		fin.read((char*)&sizeOfNameStr, sizeof(size_t));
		name = new char[sizeOfNameStr];
		fin.read(name, sizeOfNameStr);

		fin.read((char*)&sizeOfDateStr, sizeof(size_t));
		date = new char[sizeOfDateStr];
		fin.read(date, sizeOfDateStr);

		if (fin.good())
		{
			cout << "===========" << endl
				<< name << endl
				<< date << endl;
		}

		if (name != nullptr && date != nullptr)
		{
			delete[] name;
			delete[] date;
		}
	}
}