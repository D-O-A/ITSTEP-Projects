#include <iostream>
using namespace std;

struct Fraction
{
	int numerator;
	int denominator;
};

//тип функции - наша структура, чтобы возвращала нам результат работы как структуру
Fraction AddFractions(const Fraction& a, const Fraction& b)
{
	return { a.numerator * b.denominator + a.denominator * b.numerator, a.denominator * b.denominator };
}

Fraction SubtrFractions(const Fraction& a, const Fraction& b)
{
	return { a.numerator * b.denominator - a.denominator * b.numerator, a.denominator * b.denominator };
}

Fraction MultiplyFractions(const Fraction& a, const Fraction& b)
{
	return { a.numerator * b.numerator, a.denominator * b.denominator };
}

Fraction DivideFractions(const Fraction& a, const Fraction& b)
{
	return { a.numerator * b.denominator, a.denominator * b.numerator };
}

void PrintFraction(const Fraction& a)
{
	cout << a.numerator << '/' << a.denominator << endl;
}

int main()
{
	//тут задаем дроби, лень писать функцию, чтоб пользователь вводил :)
	Fraction a = { 2, 3 };
	Fraction b = { 3, 4 };

	//передаем результат работы одной функции в качестве параметров для другой
	cout << "Add: ";
	PrintFraction(AddFractions(a, b));

	cout << "Subtract: ";
	PrintFraction(SubtrFractions(a, b));

	cout << "Multiply: ";
	PrintFraction(MultiplyFractions(a, b));

	cout << "Divide: ";
	PrintFraction(DivideFractions(a, b));
}