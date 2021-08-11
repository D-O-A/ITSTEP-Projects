#pragma once
class UI
{
public:

	static double EnterWeight_kg();
	static unsigned EnterDistance_km();
	static TransportType EnterTransportType();

	static void PrintCost(double cost);
	static void PrintDays(unsigned days);
};

