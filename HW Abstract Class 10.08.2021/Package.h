#pragma once

enum class TransportType
{
	TRUCK = 1,
	SHIP,
	PLANE
};

class Package
{
public:

	Package() = default;

	void SetWeight_kg(double weight);
	void SetDistance_km(unsigned distance);
	void SetTransportType(TransportType transportType);

	double GetWeight_kg();
	unsigned GetDistance_km();
	TransportType GetTransportType();

private:

	double weight_kg_ = 0;
	unsigned distance_km_ = 0;
	TransportType transportType_ = TransportType::TRUCK;
};

