#pragma once
#include "Headers.h"
class ForeignPassport : public Passport
{
	friend ostream& operator<< (ostream& cout, const ForeignPassport& passport);
	friend istream& operator>> (istream& cin, ForeignPassport& passport);

public:

	ForeignPassport() = default;
	ForeignPassport(string nationality, string dateofissue, string dateofexpiry, string countrycode);
	ForeignPassport(string nationality, string dateofissue, string dateofexpiry);
	ForeignPassport(string nationality, string dateofissue);
	ForeignPassport(string nationality);


	void SetNationality(string nationality) { nationality_ = nationality; }
	void SetDateOfIssue(string dateofissue) { dateOfIssue_ = dateofissue; }
	void SetDateOfExpiry(string dateofexpiry) { dateOfExpiry_ = dateofexpiry; }
	void SetCountryCode(string countrycode) { countryCode_ = countrycode; }

	string GetNationality() { return nationality_; }
	string GetDateOfIssue() { return dateOfIssue_; }
	string GetDateofExpiry() { return dateOfExpiry_; }
	string GetCountryCode() { return countryCode_; }

protected:

	string nationality_ = "undefined";
	string dateOfIssue_ = "undefined";
	string dateOfExpiry_ = "undefined";
	string countryCode_ = "undefined";

};