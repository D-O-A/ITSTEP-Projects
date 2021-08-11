#include "Headers.h"

double Ship::CalculateCost(Package& package)
{
	double cost;

	// вес * расстояние * 0.25
	cost = package.GetWeight_kg() * (package.GetDistance_km() * 0.25);

	return cost;
}

unsigned Ship::CalculateDays(Package& package)
{
	unsigned days;

	// расстояние / вес * 3
	days = package.GetDistance_km() / (package.GetWeight_kg() * 3);

	return days;
}
