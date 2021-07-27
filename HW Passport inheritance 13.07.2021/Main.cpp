#include "Headers.h"

int main()
{
	Passport domPassport;
	ForeignPassport forPassport("Ukraine", "08.09.2020", "12.10.2027", "UKR");

	cout << domPassport << endl;
	cout << forPassport;

	forPassport.SetName("Valeria");

	cout << "\n\n";

	cout << forPassport.GetName() << endl;

	cout << "\n\n";

	cout << forPassport;

	cout << "\n\n";

	cin >> forPassport;

	system("cls");

	cout << forPassport;
}