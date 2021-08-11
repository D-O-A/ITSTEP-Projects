#pragma once
#include "Headers.h"
class MultiCurrencyAccount : public Account
{
	friend class Debug;

public:

	MultiCurrencyAccount() = default;
	MultiCurrencyAccount(string fullname, unsigned accountid, double cashamount, double usdCash);

	void SetUsdCash(double usdCash);

	double GetUsdCash();

private:

	double usdCash_ = 0;
};