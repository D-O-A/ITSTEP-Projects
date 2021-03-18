#include <iostream>
using namespace std;

double USDtoUAH(int choice, double unit)
{
	const double EXRATE = 27.80;
	double conv_uah_to_usd = unit / EXRATE,
		   conv_usd_to_uah = unit * EXRATE;
	if (choice == 1)
		return conv_usd_to_uah;
	else if (choice == 2)
		return conv_uah_to_usd;
}

double MItoKM(int choice, double unit)
{
	const double KM_IN_MI = 1.609;
	double mi_to_km = KM_IN_MI * unit, 
		   km_to_mi = unit / KM_IN_MI;
	if (choice == 3)
		return mi_to_km;
	else if (choice == 4)
		return km_to_mi;
}

double LBtoKG(int choice, double unit)
{
	const double LB_IN_KG = 2.2046;
	double kg_to_lb = unit * LB_IN_KG,
		   lb_to_kg = unit / LB_IN_KG;
	if (choice == 5)
		return lb_to_kg;
	else if (choice == 6)
		return kg_to_lb;
}

double INCHtoCM(int choice, double unit)
{
	const double CM_IN_INCH = 2.54;
	double cm_to_in = unit / CM_IN_INCH,
		   in_to_cm = unit * CM_IN_INCH;
	if (choice == 7)
		return in_to_cm;
	else if (choice == 8)
		return cm_to_in;
}

double CtoF(int choice, double unit)
{
	const double ZERO_C_IN_F = 32, ONE_DEGREE_C_IN_F = 1.8;
	double  c_to_f = unit * ONE_DEGREE_C_IN_F + ZERO_C_IN_F, 
		  f_to_c = (unit - ZERO_C_IN_F) / ONE_DEGREE_C_IN_F;
	if (choice == 9)
		return c_to_f;
	else if (choice == 10)
		return f_to_c;
}

void PrintChoice()
{
	cout << "1:USD -> UAH\n"
		 << "2:UAH -> USD\n"
	     << "3:Мили -> Километры\n"
		 << "4:Километры -> Мили\n"
	     << "5:Фунты -> Килограммы\n"
		 << "6:Килограммы -> Фунты\n"
		 << "7:Дюймы -> Сантиметры\n"
		 << "8:Сантиметры -> Дюймы\n"
		 << "9:Цельсий -> Фаренгейт\n"
		 << "10:Фаренгейт -> Цельсий\n"
		 << "0:Выход\n\n";
}

int GetMenuChoice()
{
	int choice;
	do
	{
		cout << "Выберите действие:"; cin >> choice;
		cout << endl;
	} while (choice < 0 || choice > 10);
	return choice;
}

double EnterUnit()
{
	double unit;
	cout << "Введите исходную валюту/единицу измерения:"; cin >> unit;
	return unit;
}

void Conversion(int choice, double unit)
{
	switch (choice)
	{
	case 1:
		cout << unit << " USD = " << USDtoUAH(choice, unit) << " UAH";
		break;
	case 2:
		cout << unit << " UAH = " << USDtoUAH(choice, unit) << " USD";
		break;
	case 3:
		cout << unit << " MI = " << MItoKM(choice, unit) << " KM";
	case 4:
		cout << unit << " KM = " << MItoKM(choice, unit) << " MI";
		break;
	case 5:
		cout << unit << " LB = " << LBtoKG(choice, unit) << " KG";
		break;
	case 6:
		cout << unit << " KG = " << LBtoKG(choice, unit) << " LB";
		break;
	case 7:
		cout << unit << " IN = " << INCHtoCM(choice, unit) << " CM";
		break;
	case 8:
		cout << unit << " CM = " << INCHtoCM(choice, unit) << " IN";
		break;
	case 9:
		cout << unit << " C = " << CtoF(choice, unit) << " F";
		break;
	case 10:
		cout << unit << " F = " << CtoF(choice, unit) << " C";
	}
	cout << endl << endl;
}

int main()
{
	cout << "1.\n\n";

	//1. Аналогичным "Калькулятору" образом переделать программу пересчета валют и мер (все, что делали раньше).

	setlocale(LC_ALL, "Russian");

	while (true)
	{
		PrintChoice();

		int choice = GetMenuChoice();

		if (!choice)
		{
			cout << "o7\n";
			break;
		}

		double unit = EnterUnit();

		Conversion(choice, unit);
	}
}