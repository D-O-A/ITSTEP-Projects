#pragma once
#include "Headers.h"

class Debug
{
public:

	static void PrintATMFields(ATM object)
	{
		cout << "id number: " << object.idNumber_ << endl
			<< "cash left: " << object.GetCashReserve() << endl
			<< "minimum withdraw per day: " << object.minWithdrawPerDay_ << endl
			<< "maximum withdraw per day: " << object.maxWithdrawPerDay_ << endl
			<< "USD exchange rate: " << object.usdExRate_ << endl;
	}

	static void PrintATMStringCashReserve(ATM object)
	{
		cout << object.GetCashReserve() << endl;
	}

	static void PrintAccountFields(Account* account)
	{
		cout << "full name: " << account.fullName_ << endl
			<< "account id: " << account.accountID_ << endl
			<< "cash amount: " << account.cashAmount_ << endl;
	}

	static void PrintAccountFields(CreditAccount account)
	{
		cout << "full name: " << account.fullName_ << endl
			<< "account id: " << account.accountID_ << endl
			<< "cash amount: " << account.cashAmount_ << endl
			<< "credit limit: " << account.creditLimit_ << endl;
	}

	static void PrintAccountFields(MultiCurrencyAccount account)
	{
		cout << "full name: " << account.fullName_ << endl
			<< "account id: " << account.accountID_ << endl
			<< "cash amount: " << account.cashAmount_ << endl
			<< "usd cash amount: " << account.usdCash_ << endl;
	}
};