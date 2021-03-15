#include <iostream>
using namespace std;

bool LuckyTicket(int ticket_num)
{
	//код и переменные взял с задания про счастливый билет
	int first_digit, second_digit, third_digit, fourth_digit,
		fifth_digit, sixth_digit, sum_digit_first, sum_digit_last;

	first_digit = ticket_num / 100000;
	second_digit = ticket_num / 10000 % 10;
	third_digit = ticket_num / 1000 % 10;
	fourth_digit = ticket_num / 100 % 10;
	fifth_digit = ticket_num / 10 % 10;
	sixth_digit = ticket_num % 10;
	sum_digit_first = first_digit + second_digit + third_digit;
	sum_digit_last = fourth_digit + fifth_digit + sixth_digit;

	if (sum_digit_first == sum_digit_last)
		return true;
	else
		return false;
}

int main()
{
	cout << "12.\n\n";

	//Написать функцию, которая определяет является ли «счастливым» заданное шестизначное число.

	setlocale(LC_ALL, "Russian");

	int ticket_num;

	cout << "Введите шестизначное число:"; cin >> ticket_num;

	if (LuckyTicket(ticket_num))
		cout << "Это число является счастливым!\n";
	else
		cout << "Это число не является счастливым!:(\n";
}