#pragma once
#include "Headers.h"

class Account
{
	friend class Debug;

public:

	Account() = default;
	Account(string fullname, unsigned accountid, double cashamount);

	double GetCashAmount();

	virtual void WithdrawCash(Account* account, ATM& atm);
	virtual void TopUpAccount(Account* account, ATM& atm);

	void SetCashAmount(double cashamount);

	virtual void PrintAccountFields(Account* account)
	{
		cout << "full name: " << account->fullName_ << endl
			<< "account id: " << account->accountID_ << endl
			<< "cash amount: " << account->cashAmount_ << endl;
	}

private:

	string fullName_ = "undefined";
	unsigned accountID_ = 000000;
	double cashAmount_ = 0.0;
};