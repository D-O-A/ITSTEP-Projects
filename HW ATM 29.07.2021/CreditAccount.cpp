#include "Headers.h"

CreditAccount::CreditAccount(string fullname, unsigned accountid, double cashamount, double creditlimit) : Account(fullname, accountid, cashamount)
{
	SetCreditLimit(creditlimit);
	SetCreditLimitOriginal(creditLimit_);
}

void CreditAccount::SetCreditLimit(double creditlimit)
{
	creditLimit_ = creditlimit;
}

void CreditAccount::SetCreditLimitOriginal(double creditlimit)
{
	creditLimitOriginal_ = creditLimit_;
}

void CreditAccount::WithdrawCash(Account* account, ATM& atm)
{
	double amount;
	double initialAmount;
	double creditLimit = account->GetCreditLimit();
	double cashAmount = account->GetCashAmount();

	do
	{
		amount = atm.EnterAmountToWithdraw();
		initialAmount = amount;

		if (amount <= account->GetCashAmount())
		{
			double cashAmount = account->GetCashAmount();
			cashAmount -= amount;

			account->SetCashAmount(cashAmount);

			double cashReserve = atm.GetCashReserve_d();
			cashReserve -= amount;

			atm.SetCashReserve(cashReserve);

			cout << "Withdrawal successful!" << endl;
		}
		else if (amount <= cashAmount + creditLimit)
		{
			amount -= cashAmount;
			creditLimit -= amount;

			account->SetCreditLimit(creditLimit);
			account->SetCashAmount(0.0);

			double cashReserve = atm.GetCashReserve_d();

			cashReserve -= initialAmount;
			atm.SetCashReserve(cashReserve);

			cout << "Withdrawal successful!" << endl;
		}
		else
		{
			cout << "Insufficient funds to withdraw!" << endl;
		}

	} while (amount > cashAmount + creditLimit);
}

double CreditAccount::GetCreditLimit()
{
	return creditLimit_;
}

double CreditAccount::GetCreditLimitOriginal()
{
	return creditLimitOriginal_;
}