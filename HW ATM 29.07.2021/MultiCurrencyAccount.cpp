#include "Headers.h"

MultiCurrencyAccount::MultiCurrencyAccount(string fullname, unsigned accountid, double cashamount, double usdCash) : Account(fullname, accountid, cashamount)
{
	SetUsdCash(usdCash);
}

void MultiCurrencyAccount::SetUsdCash(double usdCash)
{
	usdCash_ = usdCash;
}

double MultiCurrencyAccount::GetUsdCash()
{
	return usdCash_;
}