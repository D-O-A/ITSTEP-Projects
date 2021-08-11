#include "Headers.h"

double UI::EnterWeight_kg()
{
	double weight;

	cout << "Enter weight (kg): ";
	cin >> weight;

	return weight;
}

unsigned UI::EnterDistance_km()
{
	unsigned distance;

	cout << "Enter distance (km): ";
	cin >> distance;

	return distance;
}

TransportType UI::EnterTransportType()
{
	TransportType type;
	unsigned choice;

	cout << "Choose transport type:\n"
		<< "1 - Truck.\n"
		<< "2 - Ship.\n"
		<< "3 - Plane." << endl;
	cin >> choice;

	return (TransportType)choice;
}

void UI::PrintCost(double cost)
{
	cout << "Cost - " << cost << endl;
}

void UI::PrintDays(unsigned days)
{
	cout << "Days - " << days << endl;
}
