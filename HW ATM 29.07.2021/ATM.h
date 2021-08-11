#pragma once
#include "Headers.h"

class ATM
{
	friend class Debug;

public:

	ATM() = default;
	ATM(unsigned idNumber, double cashReserve, double minWithdrawPerDay, double maxWidthdrawPerDay, double usdExRate);

	//void WithdrawCash(Account& account);
	//void WithdrawCash(CreditAccount& account);
	//void WithdrawCash(MultiCurrencyAccount& account);

	//void TopUpAccount(Account& account);
	//void TopUpAccount(CreditAccount& account);
	//void TopUpAccount(MultiCurrencyAccount& account);

	unsigned GetId();
	double GetCashReserve_d();
	string GetCashReserve();
	double GetMinWIthdrawPerDay();
	double GetMaxWithdrawPerDay();
	double GetUsdExRate();

	void SetId(unsigned id);
	void SetCashReserve(double cashReserve);
	void SetMinWithdrawPerDay(double minWithdrawPerDay);
	void SetMaxWithdrawPerDay(double maxWithdrawPerDay);
	void SetUsdExRate(double usdExRate);

	double ConverToUsd(double amount);
	double ConverToUah(double amount);

	double EnterAmountToWithdraw_usd();
	double EnterAmountToWithdraw();
	double EnterAmountToTopUp_usd();
	double EnterAmountToTopUp();

private:

	bool IsOutOfRange(double amount);

	string ToString(double cashReserve);
	//double EnterAmountToWithdraw_usd();
	//double EnterAmountToWithdraw();
	//double EnterAmountToTopUp_usd();
	//double EnterAmountToTopUp();

	unsigned idNumber_ = rand() % 9999999 + 1000000;
	double cashReserve_ = 100000.00;
	double minWithdrawPerDay_ = 100.00;
	double maxWithdrawPerDay_ = 30000.00;
	double usdExRate_ = 27.05;
};