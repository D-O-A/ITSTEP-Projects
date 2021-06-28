#include "MyString.h"
#include <iostream>
using namespace std;

MyStringClass::MyStringClass(const char* str)
{
	Copy(str);
}

MyStringClass::~MyStringClass()
{
	Clear();
}

MyStringClass::MyStringClass(const MyStringClass& str)
{
	str_len_ = str.str_len_;
	pstr_ = new char[str_len_];

	for (size_t i = 0; i < str_len_; i++)
	{
		pstr_[i] = str.pstr_[i];
	}
}

size_t MyStringClass::MyStrLen(const char* str) const
{
	size_t length = 0;

	while (str[length] != '\0')
	{
		length++;
	}

	return length;
}

void MyStringClass::Append(const char* str)
{
	if (pstr_ == nullptr)
	{
		cout << "Please Assign a string first.\n";
		return;
	}

	size_t length = MyStrLen(str);
	size_t new_str_length = str_len_ + length + 1;

	char* temp = new char[new_str_length];

	for (size_t i = 0; i < str_len_; i++)
	{
		temp[i] = pstr_[i];
	}

	temp[str_len_] = ' ';

	for (size_t i = str_len_ + 1; i < new_str_length; i++)
	{
		temp[i] = str[i - (str_len_ + 1)];
	}

	delete[] pstr_;
	pstr_ = temp;
	str_len_ = new_str_length;
}

void MyStringClass::Assign(const char* str)
{
	size_t length = MyStrLen(str);

	char* temp = new char[length];

	for (size_t i = 0; i < length; i++)
	{
		temp[i] = str[i];
	}

	if (pstr_ != nullptr)
	{
		delete[] pstr_;
	}

	pstr_ = temp;
	str_len_ = length;
}

void MyStringClass::Insert(size_t index, const char* str)
{
	size_t length = MyStrLen(str);

	//если новая строка "влазит" в существующую
	if (index + length <= str_len_)
	{
		for (size_t i = index; i < str_len_; i++)
		{
			pstr_[i] = str[i - index];
		}
	}
	else
	{
		char* temp = new char[index + length];

		//копирование существующей строки
		for (size_t i = 0; i < str_len_; i++)
		{
			temp[i] = pstr_[i];
		}

		//заполнение пробелами если новая строка не "влазит" в существующую строку
		for (size_t i = str_len_; i < (index + length) - length; i++)
		{
			temp[i] = ' ';
		}

		//добавление новой строки с указанного индекса
		for (size_t i = index; i < index + length; i++)
		{
			temp[i] = str[i - index];
		}

		delete[] pstr_;
		pstr_ = temp;
		str_len_ = index + length;
	}
}

void MyStringClass::Remove(size_t index, size_t length)
{
	if (length > str_len_)
	{
		cout << "You can't remove whole string";
		return;
	}

	char* temp = new char[str_len_ - length];

	for (size_t i = 0; i < str_len_ - length; i++)
	{
		if (i < index - 1 || i >((index - 1) + length) - 1)
		{
			temp[i] = pstr_[i];
		}
		else
		{
			temp[i] = ' ';
		}
	}

	delete[] pstr_;
	pstr_ = temp;
	str_len_ = str_len_ - length;
}

MyStringClass& MyStringClass::operator=(const MyStringClass& str)
{
	if (this != &str)
	{
		Clear();
		Copy(str);
	}

	return *this;
}

MyStringClass& MyStringClass::operator=(MyStringClass&& str)
{
	if (this != &str)
	{
		Clear();
		this->pstr_ = str.pstr_;
		this->str_len_ = str.str_len_;

		str.pstr_ = nullptr;
		str.str_len_ = 0;
	}
	
	return *this;
}

char* MyStringClass::operator[](const char* str)
{
	for (size_t i = 0; i < str_len_; i++)
	{
		if (_stricmp(pstr_, str) == 0)
		{
			return pstr_;
		}
	}

	return nullptr;
}

//debug
void MyStringClass::PrintStr() const
{
	for (size_t i = 0; i < str_len_; i++)
	{
		cout << pstr_[i];
	}
}

void MyStringClass::Copy(const MyStringClass& str)
{
	str_len_ = str.str_len_;
	pstr_ = new char[str_len_];

	for (size_t i = 0; i < str_len_; i++)
	{
		pstr_[i] = str.pstr_[i];
	}
}

void MyStringClass::Clear()
{
	if (pstr_ != nullptr)
	{
		delete[] pstr_;
		pstr_ = nullptr;
		str_len_ = 0;
	}
}
