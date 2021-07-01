#include "Fraction.h"

Fraction::Fraction(int numerator)
{
	numerator_ = numerator;
}

Fraction::Fraction(int numerator, int denominator) : Fraction(numerator)
{
	if (denominator != 0)
	{
		denominator_ = denominator;
	}
}

int Fraction::GetNumerator() const
{
	return numerator_;
}

int Fraction::GetDenominator() const
{
	return denominator_;
}

void Fraction::SetNumerator(int numerator)
{
	numerator_ = numerator;
}

void Fraction::SetDenominator(int denominator)
{
	denominator_ = denominator;
}

void Fraction::PrintFraction()
{
	cout << numerator_ << " / " << denominator_ << endl;
}

Fraction Fraction::operator+(const Fraction& rOp)
{
	Fraction res;

	res.numerator_ = numerator_ + rOp.numerator_;
	res.denominator_ = denominator_;

	return res;
}

Fraction operator-(Fraction lOp, Fraction rOp)
{
	Fraction res;

	res.numerator_ = lOp.GetNumerator() - rOp.GetNumerator();
	res.denominator_ = lOp.GetDenominator();

	return res;
}

ostream& operator<<(ostream& cout, const Fraction& fr)
{
	cout << fr.numerator_ << " / " << fr.denominator_;

	return cout;
}

istream& operator>>(istream& cin, Fraction& fr)
{
	cout << "Enter numerator:";
	cin >> fr.numerator_;

	cout << "Enter denominator:";
	cin >> fr.denominator_;

	return cin;
}