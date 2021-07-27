#include "Headers.h"

Passport::Passport(string name, string surname, string idnumber, string dateofbirth, string placeofbirth, string gender, string issuedby) : name_(name), surname_(surname), idNumber_(idnumber), dateOfBirth_(dateofbirth), placeOfBirth_(placeofbirth), gender_(gender), issuedBy_(issuedby)
{
}

Passport::Passport(string name, string surname, string idnumber, string dateofbirth, string placeofbirth, string gender) : Passport(name, surname, idnumber, dateofbirth, placeofbirth, gender, "undefined")
{
}

Passport::Passport(string name, string surname, string idnumber, string dateofbirth, string placeofbirth) : Passport(name, surname, idnumber, dateofbirth, placeofbirth, "undefined", "undefined")
{
}

Passport::Passport(string name, string surname, string idnumber, string dateofbirth) : Passport(name, surname, idnumber, dateofbirth, "undefined", "undefined", "undefined")
{
}

Passport::Passport(string name, string surname, string idnumber) : Passport(name, surname, idnumber, "undefined", "undefined", "undefined", "undefined")
{
}

Passport::Passport(string name, string surname) : Passport(name, surname, "undefined", "undefined", "undefined", "undefined", "undefined")
{
}

Passport::Passport(string name) : Passport(name, "undefined", "undefined", "undefined", "undefined", "undefined", "undefined")
{
}

ostream& operator<<(ostream& cout, const Passport& passport)
{
	cout << "::Domestic passport::" << endl
		<< "Name: " << passport.name_ << endl
		<< "Surname: " << passport.surname_ << endl
		<< "ID number: " << passport.idNumber_ << endl
		<< "Date of birth: " << passport.dateOfBirth_ << endl
		<< "Place of birth: " << passport.placeOfBirth_ << endl
		<< "Gender: " << passport.gender_ << endl
		<< "Issued by: " << passport.issuedBy_ << endl;

	return cout;
}

istream& operator>>(istream& cin, Passport& passport)
{
	cout << "\nEnter name:";
	getline(cin, passport.name_);

	cout << "\nEnter surname:";
	getline(cin, passport.surname_);

	cout << "\nEnter ID number:";
	getline(cin, passport.idNumber_);

	cout << "\nEnter date of birth:";
	getline(cin, passport.dateOfBirth_);

	cout << "\nEnter place of birth:";
	getline(cin, passport.placeOfBirth_);

	cout << "\nEnter gender:";
	getline(cin, passport.gender_);

	cout << "\nEnter issued by:";
	getline(cin, passport.issuedBy_);

	return cin;
}