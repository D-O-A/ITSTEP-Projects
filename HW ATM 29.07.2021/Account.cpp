#include "Headers.h"

Account::Account(string fullname, unsigned accountid, double cashamount) : fullName_(fullname), accountID_(accountid), cashAmount_(cashamount)
{
}

double Account::GetCashAmount()
{
	return cashAmount_;
}

void Account::WithdrawCash(Account* account, ATM& atm)
{
	double amount;

	do
	{
		amount = atm.EnterAmountToWithdraw();

		if (amount > account->GetCashAmount())
		{
			cout << "Insufficient funds to withdraw!" << endl;
		}

	} while (amount > account->GetCashAmount());


	double cashAmount = account->GetCashAmount();
	cashAmount -= amount;

	account->SetCashAmount(cashAmount);

	double cashReserve = atm.GetCashReserve_d();
	cashReserve -= amount;

	atm.SetCashReserve(cashReserve);

	cout << "Withdrawal successful!" << endl;
}

void Account::TopUpAccount(Account* account, ATM& atm)
{
	double amount = atm.EnterAmountToTopUp();

	double cashAmount = account->GetCashAmount();
	cashAmount += amount;

	account->SetCashAmount(cashAmount);
	cout << "Account successfully filled!" << endl;
}

void Account::SetCashAmount(double cashamount)
{
	cashAmount_ = cashamount;
}