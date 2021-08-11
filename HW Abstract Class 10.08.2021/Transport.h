#pragma once
class Transport
{
public:

	virtual ~Transport() = 0 {};

	virtual double CalculateCost(Package& package) = 0;
	virtual unsigned CalculateDays(Package& package) = 0;

};

