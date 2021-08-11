#pragma once
#include "Transport.h"
class Truck :
    public Transport
{
public:

    virtual double CalculateCost(Package& package) override;
    virtual unsigned CalculateDays(Package& package) override;
};

