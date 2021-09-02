#include "Headers.h"

int main()
{
	OrderCollection order;

	order.AddProduct("Apple", 2, 20.50);
	order.AddProduct("Lemon", 1, 23.40);
	order.AddProduct("Plum", 2, 50.30);
	order.AddProduct("Orange", 1, 65.50);

	WriteToTxtFile::PrintToTxt(order);

}