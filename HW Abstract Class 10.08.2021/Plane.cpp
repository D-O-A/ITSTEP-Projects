#include "Headers.h"

double Plane::CalculateCost(Package& package)
{
	double cost;

	// вес * расстояние * 0.75
	cost = package.GetWeight_kg() * (package.GetDistance_km() * 0.75);

	return cost;
}

unsigned Plane::CalculateDays(Package& package)
{
	unsigned days;

	// расстояние / вес * 12
	days = package.GetDistance_km() / (package.GetWeight_kg() * 12);

	return days;
}
