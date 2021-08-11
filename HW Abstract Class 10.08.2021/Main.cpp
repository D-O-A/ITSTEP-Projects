#include "Headers.h"

int main()
{
	Package package;

	package.SetWeight_kg(UI::EnterWeight_kg());
	package.SetDistance_km(UI::EnterDistance_km());
	package.SetTransportType(UI::EnterTransportType());

	double cost = 0;
	unsigned days = 0;

	Transport* transport = nullptr;

	switch (package.GetTransportType())
	{
	case TransportType::TRUCK:
		transport = new Truck;
		break;

	case TransportType::SHIP:
		transport = new Ship;
		break;

	case TransportType::PLANE:
		transport = new Plane;
		break;
	}

	cost = transport->CalculateCost(package);
	days = transport->CalculateDays(package);

	if (transport != nullptr)
	{
		delete transport;
	}

	UI::PrintCost(cost);
	UI::PrintDays(days);

}