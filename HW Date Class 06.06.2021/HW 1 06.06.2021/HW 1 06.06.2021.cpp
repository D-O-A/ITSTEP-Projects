#include <iostream>
using namespace std;

class Date
{

	friend int operator-(Date lOp, Date rOp);
	friend ostream& operator<<(ostream& cout, const Date& date);
	friend istream& operator>>(istream& cin, Date& date);

public:

	void SetDay();
	void SetMonth();
	void SetYear();

	void AddDay();
	void AddMonth();

	void PrintDate();

	void IsLeapYear();

	Date operator++();
	Date operator++(int);
	Date operator--();
	Date operator--(int);

	bool operator==(const Date& date);
	bool operator<(const Date& date);
	bool operator<=(const Date& date);
	bool operator>(const Date& date);
	bool operator>=(const Date& date);
	bool operator!=(const Date& date);


private:

	unsigned day_;
	unsigned month_;
	unsigned year_;

};

int operator-(Date lOp, Date rOp);

int main()
{
	Date date;

	date.SetDay();
	date.SetMonth();
	date.SetYear();

	Date date2;

	date2.SetDay();
	date2.SetMonth();
	date2.SetYear();

	date.PrintDate();
	date2.PrintDate();

	cout << "\n\n\n";

	int difference = date - date2;

	cout << "Difference is " << difference << " days." << endl;

	cout << "\n\n\n";

	date++;

	cout << date << endl;

	date2--;

	cout << date2 << endl;

	if (date > date2)
	{
		cout << "Date 1 is greater!" << endl;
	}
	else
	{
		cout << "Date 2 is greater!" << endl;
	}

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

Date Date::operator++()
{
	if (day_ < 31)
	{
		day_++;
	}

	if (day_ >= 31)
	{
		day_ = 1;

		if (month_ < 12)
		{
			month_++;
		}
		else
		{
			month_ = 1;
		}
	}

	//лениво, будет баг
	if (month_ == 1)
	{
		year_++;
	}

	return *this;
}

Date Date::operator++(int)
{
	Date old_date = *this;

	if (day_ < 31)
	{
		day_++;
	}

	if (day_ >= 31)
	{
		day_ = 1;
		
		if (month_ < 12)
		{
			month_++;
		}
		else
		{
			month_ = 1;
		}
	}

	//лениво, будет баг
	if (month_ == 1)
	{
		year_++;
	}

	return old_date;
}

Date Date::operator--()
{
	if (day_ > 1)
	{
		day_--;
	}

	if (day_ <= 1)
	{
		day_ = 31;

		if (month_ > 1)
		{
			month_--;
		}
		else
		{
			month_ = 12;
		}
	}

	//лениво, будет баг
	if (month_ == 12)
	{
		year_--;
	}
	
	return *this;
}

Date Date::operator--(int)
{
	Date old_date = *this;

	if (day_ > 1)
	{
		day_--;
	}

	if (day_ <= 1)
	{
		day_ = 31;
		
		if (month_ > 1)
		{
			month_--;
		}
		else
		{
			month_ = 12;
		}
	}

	//лениво, будет баг
	if (month_ == 12)
	{
		year_--;
	}

	return old_date;
}

bool Date::operator==(const Date& date)
{
	return (day_ == date.day_ && month_ == date.month_ && year_ == date.year_);
}

bool Date::operator<(const Date& date)
{
	return year_ < date.year_ || month_ < date.month_ || day_ < date.day_;
}

bool Date::operator<=(const Date& date)
{
	return year_ <= date.year_ || month_ <= date.month_ || day_ <= date.day_;
}

bool Date::operator>(const Date& date)
{
	return year_ > date.year_ || month_ > date.month_ || day_ > date.day_;
}

bool Date::operator>=(const Date& date)
{
	return year_ >= date.year_ || month_ >= date.month_ || day_ >= date.day_;
}

bool Date::operator!=(const Date& date)
{
	return !(day_ == date.day_ && month_ == date.month_ && year_ == date.year_);
}

int operator-(Date lOp, Date rOp)
{
	int difference = lOp.day_ - rOp.day_;

	if (difference < 0)
	{
		return -difference;
	}
	else
	{
		return difference;
	}
}

ostream& operator<<(ostream& cout, const Date& date)
{
	cout << date.day_ << "." << date.month_ << "." << date.year_;
	
	return cout;
}

istream& operator>>(istream& cin, Date& date)
{
	cout << "Enter day:";
	cin >> date.day_;

	cout << "Enter month:";
	cin >> date.month_;

	cout << "Enter year:";
	cin >> date.year_;

	return cin;
}
