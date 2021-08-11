#pragma once
#include "Headers.h"
class Passport
{

	friend ostream& operator<< (ostream& cout, const Passport& passport);
	friend istream& operator>> (istream& cin, Passport& passport);

public:

	Passport() = default;
	Passport(string name, string surname, string idnumber, string dateofbirth, string placeofbirth, string gender, string issuedby);
	Passport(string name, string surname, string idnumber, string dateofbirth, string placeofbirth, string gender);
	Passport(string name, string surname, string idnumber, string dateofbirth, string placeofbirth);
	Passport(string name, string surname, string idnumber, string dateofbirth);
	Passport(string name, string surname, string idnumber);
	Passport(string name, string surname);
	Passport(string name);

	void SetName(string name) { name_ = name; }
	void SetSurname(string surname) { surname_ = surname; }
	void SetIdNumber(string idnumber) { idNumber_ = idnumber; }
	void SetDateOfBirth(string dateofbirth) { dateOfBirth_ = dateofbirth; }
	void SetPlaceOfBirth(string placeofbirth) { placeOfBirth_ = placeofbirth; }
	void SetGender(string gender) { gender_ = gender; }
	void SetIssuedBy(string issuedby) { issuedBy_ = issuedby; }

	string GetName() { return name_; }
	string GetSurname() { return surname_; }
	string GetIdNumber() { return idNumber_; }
	string GetDateOfBirth() { return dateOfBirth_; }
	string GetPlaceOfBirth() { return placeOfBirth_; }
	string GetGender() { return gender_; }
	string GetIssuedBy() { return issuedBy_; }

protected:

	string name_ = "undefined";
	string surname_ = "undefined";
	string idNumber_ = "undefined";
	string dateOfBirth_ = "undefined";
	string placeOfBirth_ = "undefined";
	string gender_ = "undefined";
	string issuedBy_ = "undefined";

};