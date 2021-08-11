#pragma once
#include "Headers.h"
class CreditAccount : public Account
{
	friend class Debug;

public:

	CreditAccount() = default;
	CreditAccount(string fullname, unsigned accountid, double cashamount, double creditlimit);

	void SetCreditLimit(double creditlimit);
	void SetCreditLimitOriginal(double creditlimit);

	virtual void WithdrawCash(Account* account, ATM& atm) override;
	virtual void TopUpAccount(Account* account, ATM& atm) override;

	double GetCreditLimit();
	double GetCreditLimitOriginal();

private:

	double creditLimit_ = 0.0;
	double creditLimitOriginal_ = creditLimit_;
};