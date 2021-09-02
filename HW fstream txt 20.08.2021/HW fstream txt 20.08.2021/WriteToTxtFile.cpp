#include "Headers.h"

void WriteToTxtFile::PrintToTxt(OrderCollection& order)
{
	ofstream fout("Order.txt");

	if (!fout.is_open())
	{
		throw exception("File not opened!");
	}

	fout << "Order N 1" << endl;

	fout << setw(55) << setfill('-') << "" << endl;
	fout << "| N | " << setw(20) << left << setfill(' ') << "Name" << " | Quantity | " << "Price | " << "Total  |" << endl;

	fout.precision(2);
	fout.flags(ios::fixed);

	size_t size = 0;
	unsigned orderCount = 1;

	for (size_t i = 0; i < order.size_; i++)
	{
		fout << setw(55) << setfill('-') << "" << endl;

		fout << "| " << orderCount << " | " << setw(20) << left << setfill(' ') << order.collection_[i].nameOfProduct_;

		fout << " | " << setw(9) << left << setfill(' ') << order.collection_[i].quantity_;

		fout << "| " << setw(5) << left << setfill(' ') << order.collection_[i].price_;

		fout << " | " << setw(6) << left << setfill(' ') << order.collection_[i].price_ * order.collection_[i].quantity_ << " |" << endl;

		orderCount++;
	}

	fout << setw(55) << setfill('-') << "" << endl;
	fout << endl;

	fout << " Total:" << setw(41) << setfill(' ') << "" << order.CalculateTotalPrice() << endl;

	fout.close();
}
