#include <iostream>
#include "Fraction.h"
using namespace std;

int main()
{
	//со школы ненавижу дроби, ненавижу и не понимаю :) 
	//с алгоритмической точки зрения - работает, с точки зрения правильности результатов... ¯\_(ツ)_/¯ извините
	//зато cout с cin'ом перегрузил :D

	Fraction fraction(3, 5);

	cout << fraction << endl;

	Fraction fraction2;

	cin >> fraction2;

	cout << fraction + fraction2 << endl;

	cout << fraction - fraction2 << endl;
}