#include "Headers.h"

double Truck::CalculateCost(Package& package)
{
	double cost;
	
	// вес * расстояние * 0.50
	cost = package.GetWeight_kg() * (package.GetDistance_km() * 0.50);

	return cost;
}

unsigned Truck::CalculateDays(Package& package)
{
	unsigned days;

	// расстояние / вес * 6
	days = package.GetDistance_km() / (package.GetWeight_kg() * 6);

	return days;
}
