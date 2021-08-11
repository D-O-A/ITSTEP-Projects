#include "Headers.h"

int main()
{
	srand((unsigned)time(0)); //?

	ATM atm;
	Account* accountDebit = new Account("NAME SURNAME", 1337, 10000);
	Account* accountCredit = new CreditAccount("ELENA SERBOVA", 2021, 20000, 10000);
	Account* accountUSD = new MultiCurrencyAccount("BLA BLA", 1998, 3000, 1000);

	accountDebit->WithdrawCash(accountDebit, atm);
	accountDebit->WithdrawCash(accountCredit, atm);
	accountDebit->WithdrawCash(accountUSD, atm);

	accountDebit->TopUpAccount(accountDebit, atm);
	accountDebit->TopUpAccount(accountCredit, atm);
	accountDebit->TopUpAccount(accountUSD, atm);





	Debug::PrintATMFields(atm);


	cout << "ATM CASH RESERVE" << endl;
	Debug::PrintATMStringCashReserve(atm);


	//cout << "DEBIT ACCOUNT" << endl;
	//Debug::PrintAccountFields(accountDebit);
	//cout << "============" << endl;

	//atm.WithdrawCash(accountDebit);
	//cout << "============" << endl;

	//Debug::PrintAccountFields(accountDebit);
	//cout << "============" << endl;

	//atm.TopUpAccount(accountDebit);
	//cout << "============" << endl;

	//Debug::PrintAccountFields(accountDebit);
	//cout << "============" << endl;

	//Debug::PrintATMFields(atm);


	//cout << "CREDIT ACCOUNT" << endl;
	//Debug::PrintAccountFields(accountCredit);
	//cout << "============" << endl;

	//atm.WithdrawCash(accountCredit);
	//cout << "============" << endl;

	//Debug::PrintAccountFields(accountCredit);
	//cout << "============" << endl;

	//atm.TopUpAccount(accountCredit);
	//cout << "============" << endl;

	//Debug::PrintAccountFields(accountCredit);
	//cout << "============" << endl;

	//Debug::PrintATMFields(atm);


	//cout << "USD ACCOUNT" << endl;
	//Debug::PrintAccountFields(accountUSD);
	//cout << "============" << endl;

	//atm.WithdrawCash(accountUSD);
	//cout << "============" << endl;

	//Debug::PrintAccountFields(accountUSD);
	//cout << "============" << endl;

	//atm.TopUpAccount(accountUSD);
	//cout << "============" << endl;

	//Debug::PrintAccountFields(accountUSD);
	//cout << "============" << endl;

	//Debug::PrintATMFields(atm);
}