#include "Headers.h"

void Package::SetWeight_kg(double weight)
{
	weight_kg_ = weight;
}

void Package::SetDistance_km(unsigned distance)
{
	distance_km_ = distance;
}

void Package::SetTransportType(TransportType transportType)
{
	transportType_ = transportType;
}

double Package::GetWeight_kg()
{
	return weight_kg_;
}

unsigned Package::GetDistance_km()
{
	return distance_km_;
}

TransportType Package::GetTransportType()
{
	return transportType_;
}
