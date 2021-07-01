#pragma once
#include <iostream>
using namespace std;

class Fraction
{
public:

	friend Fraction operator-(Fraction lOp, Fraction rOp);
	friend ostream& operator<< (ostream& cout, const Fraction& fr);
	friend istream& operator>> (istream& cin, Fraction& fr);

	Fraction() = default;
	explicit Fraction(int numerator);
	Fraction(int numerator, int denominator);

	int GetNumerator() const;
	int GetDenominator() const;

	void SetNumerator(int numerator);
	void SetDenominator(int denominator);

	void PrintFraction();

	Fraction operator+(const Fraction& rOp);

private:

	int numerator_ = 0;
	int denominator_ = 1;

};

Fraction operator-(Fraction lOp, Fraction rOp);