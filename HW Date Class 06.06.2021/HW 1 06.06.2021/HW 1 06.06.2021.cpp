#include <iostream>
using namespace std;

class Date
{
private:

	unsigned day_;
	unsigned month_;
	unsigned year_;

public:

	void SetDay();

	void AddDay();

	void SetMonth();

	void AddMonth();

	void SetYear();

	void PrintDate();

	void IsLeapYear();

} date;


int main()
{
	date.SetDay();

	date.SetMonth();

	date.SetYear();

	date.PrintDate();

	date.AddDay();

	date.PrintDate();

	date.AddMonth();

	date.PrintDate();

	date.IsLeapYear();
}


void Date::SetDay()
{
	unsigned day;

	cout << "Enter day:";
	cin >> day;

	while (day > 31)
	{
		if (day > 31)
		{
			cout << "Wrong day, try again:";
			cin >> day;
		}
	}

	day_ = day;
}

void Date::AddDay()
{
	unsigned day;

	cout << "Enter day:";
	cin >> day;

	unsigned result = day_ + day;

	unsigned counter = 0;

	if (result > 31)
	{
		month_++;

		for (int i = result; i > 31; i--)
		{
			counter++;
		}

		day_ = 0 + counter;
	}

	if (result <= 31)
	{
		day_ += day;
	}
}

void Date::SetMonth()
{
	unsigned month;

	cout << "Enter month:";
	cin >> month;

	while (month > 12)
	{
		if (month > 12)
		{
			cout << "Wrong month, try again:";
			cin >> month;
		}
	}

	month_ = month;
}

void Date::AddMonth()
{
	unsigned month;

	cout << "Enter month:";
	cin >> month;

	unsigned result = month_ + month;

	unsigned counter = 0;

	if (result > 12)
	{
		year_++;

		for (int i = result; i > 12; i--)
		{
			counter++;
		}

		month_ = 0 + counter;
	}

	if (result <= 12)
	{
		month_ += month;
	}
}

void Date::SetYear()
{
	unsigned year;

	cout << "Enter year:";
	cin >> year;

	while (year > 9999)
	{
		if (year > 9999)
		{
			cout << "Wrong year, try again:";
			cin >> year;
		}
	}

	year_ = year;
}

void Date::PrintDate()
{
	cout << day_ << "." << month_ << "." << year_ << endl;
}

void Date::IsLeapYear()
{
	cout << year_ << " is" << ((((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0)) ? "" : " not") << " a leap year." << endl;
}