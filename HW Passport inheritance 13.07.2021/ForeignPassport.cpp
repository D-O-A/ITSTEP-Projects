#include "ForeignPassport.h"

ForeignPassport::ForeignPassport(string nationality, string dateofissue, string dateofexpiry, string countrycode) : nationality_(nationality), dateOfIssue_(dateofissue), dateOfExpiry_(dateofexpiry), countryCode_(countrycode)
{
}

ForeignPassport::ForeignPassport(string nationality, string dateofissue, string dateofexpiry) : ForeignPassport(nationality, dateofissue, dateofexpiry, "undefined")
{
}

ForeignPassport::ForeignPassport(string nationality, string dateofissue) : ForeignPassport(nationality, dateofissue, "undefined", "undefined")
{
}

ForeignPassport::ForeignPassport(string nationality) : ForeignPassport(nationality, "undefined", "undefined", "undefined")
{
}

ostream& operator<<(ostream& cout, const ForeignPassport& passport)
{
	cout << "::Foreign passport::" << endl
		<< "Name: " << passport.name_ << endl
		<< "Surname: " << passport.surname_ << endl
		<< "ID number: " << passport.idNumber_ << endl
		<< "Date of birth: " << passport.dateOfBirth_ << endl
		<< "Place of birth: " << passport.placeOfBirth_ << endl
		<< "Gender: " << passport.gender_ << endl
		<< "Issued by: " << passport.issuedBy_ << endl
        << "Nationality: " << passport.nationality_ << endl
		<< "Date of issue: " << passport.dateOfIssue_ << endl
		<< "Date of expiry: " << passport.dateOfExpiry_ << endl
		<< "Country code: " << passport.countryCode_ << endl;

	return cout;
}

istream& operator>>(istream& cin, ForeignPassport& passport)
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

	cout << "\nEnter nationality:";
	getline(cin, passport.nationality_);

	cout << "\nEnter date of issue:";
	getline(cin, passport.dateOfIssue_);

	cout << "\nEnter date of expiry:";
	getline(cin, passport.dateOfExpiry_);

	cout << "\nEnter country code:";
	getline(cin, passport.countryCode_);

	return cin;
}