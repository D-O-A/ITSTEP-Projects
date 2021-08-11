#include "Headers.h"

ATM::ATM(unsigned idNumber, double cashReserve, double minWithdrawPerDay, double maxWidthdrawPerDay, double usdExRate)
	: idNumber_(idNumber), cashReserve_(cashReserve), minWithdrawPerDay_(minWithdrawPerDay), maxWithdrawPerDay_(maxWidthdrawPerDay), usdExRate_(usdExRate)
{
}

void ATM::SetId(unsigned id)
{
	idNumber_ = id;
}

void ATM::SetCashReserve(double cashReserve)
{
	cashReserve_ = cashReserve;
}

void ATM::SetMinWithdrawPerDay(double minWithdrawPerDay)
{
	minWithdrawPerDay_ = minWithdrawPerDay;
}

void ATM::SetMaxWithdrawPerDay(double maxWithdrawPerDay)
{
	maxWithdrawPerDay_ = maxWithdrawPerDay;
}

void ATM::SetUsdExRate(double usdExRate)
{
	usdExRate_ = usdExRate;
}

//void ATM::WithdrawCash(Account& account)
//{
//	double amount;
//
//	do
//	{
//		amount = EnterAmountToWithdraw();
//
//		if (amount > account.GetCashAmount())
//		{
//			cout << "Insufficient funds to withdraw!" << endl;
//		}
//
//	} while (amount > account.GetCashAmount());
//
//
//	double cashAmount = account.GetCashAmount();
//	cashAmount -= amount;
//
//	account.SetCashAmount(cashAmount);
//
//	cashReserve_ -= amount;
//
//	cout << "Withdrawal successful!" << endl;
//}
//
//void ATM::WithdrawCash(CreditAccount& account)
//{
//	double amount;
//	double initialAmount;
//	double creditLimit = account.GetCreditLimit();
//	double cashAmount = account.GetCashAmount();
//
//	do
//	{
//		amount = EnterAmountToWithdraw();
//		initialAmount = amount;
//
//		if (amount <= account.GetCashAmount())
//		{
//			double cashAmount = account.GetCashAmount();
//			cashAmount -= amount;
//
//			account.SetCashAmount(cashAmount);
//
//			cashReserve_ -= amount;
//
//			cout << "Withdrawal successful!" << endl;
//		}
//		else if (amount <= cashAmount + creditLimit)
//		{
//			amount -= cashAmount;
//			creditLimit -= amount;
//
//			account.SetCreditLimit(creditLimit);
//			account.SetCashAmount(0.0);
//
//			cashReserve_ -= initialAmount;
//
//			cout << "Withdrawal successful!" << endl;
//		}
//		else
//		{
//			cout << "Insufficient funds to withdraw!" << endl;
//		}
//
//	} while (amount > cashAmount + creditLimit);
//}
//
//void ATM::WithdrawCash(MultiCurrencyAccount& account)
//{
//	double amount;
//
//	do
//	{
//		amount = EnterAmountToWithdraw_usd();
//
//		if (amount > account.GetUsdCash())
//		{
//			cout << "Insufficient funds to withdraw!" << endl;
//		}
//
//	} while (amount > account.GetUsdCash());
//
//	double cashAmount = account.GetUsdCash();
//	cashAmount -= amount;
//
//	account.SetUsdCash(cashAmount);
//
//	cashReserve_ -= ConverToUah(amount);
//
//	cout << "Withdrawal successful!" << endl;
//}
//
//void ATM::TopUpAccount(Account& account)
//{
//	double amount = EnterAmountToTopUp();
//
//	double cashAmount = account.GetCashAmount();
//	cashAmount += amount;
//
//	account.SetCashAmount(cashAmount);
//	cout << "Account successfully filled!" << endl;
//}
//
//void ATM::TopUpAccount(CreditAccount& account)
//{
//	double amount = EnterAmountToTopUp();
//
//	double creditLimit = account.GetCreditLimit();
//	double creditLimitOriginal = account.GetCreditLimitOriginal();
//	double cashAmount = account.GetCashAmount();
//
//	if (creditLimit < creditLimitOriginal)
//	{
//		double fillCreditLimit = creditLimitOriginal - creditLimit;
//
//		amount -= fillCreditLimit;
//
//		fillCreditLimit += creditLimit;
//
//		account.SetCreditLimit(fillCreditLimit);
//		account.SetCashAmount(amount);
//	}
//	else 
//	{
//		cashAmount += amount;
//
//		account.SetCashAmount(cashAmount);
//		cout << "Account successfully filled!" << endl;
//	}
//}
//
//void ATM::TopUpAccount(MultiCurrencyAccount& account)
//{
//	double amount = EnterAmountToTopUp_usd();
//
//	double usdAmount = account.GetUsdCash();
//	usdAmount += amount;
//	
//	account.SetUsdCash(usdAmount);
//	cout << "Account successfully filled!" << endl;
//}

unsigned ATM::GetId()
{
	return idNumber_;
}

double ATM::GetCashReserve_d()
{
	return cashReserve_;
}

string ATM::GetCashReserve()
{
	return ToString(cashReserve_);
}

double ATM::GetMinWIthdrawPerDay()
{
	return minWithdrawPerDay_;
}

double ATM::GetMaxWithdrawPerDay()
{
	return maxWithdrawPerDay_;
}

double ATM::GetUsdExRate()
{
	return usdExRate_;
}

bool ATM::IsOutOfRange(double amount)
{
	return (amount < minWithdrawPerDay_ || amount > maxWithdrawPerDay_);
}

string ATM::ToString(double cashreserve)
{
	return to_string(cashreserve);
}

double ATM::EnterAmountToWithdraw_usd()
{
	double amount;
	double initialAmount;

	do
	{
		cout << "Enter USD withdraw amount:";
		cin >> amount;
		initialAmount = amount;

		amount = ConverToUah(amount);

		if (IsOutOfRange(amount))
		{
			cout << "Incorrect sum!\n"
				<< "Minimum withdraw amount - " << minWithdrawPerDay_ << " UAH." << endl
				<< "Maximum withdraw amount - " << maxWithdrawPerDay_ << " UAH." << endl;
		}

	} while (IsOutOfRange(amount));

	return initialAmount;
}

double ATM::EnterAmountToWithdraw()
{
	double amount;

	do
	{
		cout << "Enter withdraw amount:";
		cin >> amount;

		if (IsOutOfRange(amount))
		{
			cout << "Incorrect sum!\n"
				<< "Minimum withdraw amount - " << minWithdrawPerDay_ << " UAH." << endl
				<< "Maximum withdraw amount - " << maxWithdrawPerDay_ << " UAH." << endl;
		}

	} while (IsOutOfRange(amount));

	return amount;
}

double ATM::EnterAmountToTopUp_usd()
{
	double amount;

	cout << "Enter USD amount to top up balance:";
	cin >> amount;

	return amount;
}

double ATM::EnterAmountToTopUp()
{
	double amount;

	cout << "Enter amount to top up balance:";
	cin >> amount;

	return amount;
}

double ATM::ConverToUsd(double amount)
{
	return amount / usdExRate_;
}

double ATM::ConverToUah(double amount)
{
	return amount * usdExRate_;
}