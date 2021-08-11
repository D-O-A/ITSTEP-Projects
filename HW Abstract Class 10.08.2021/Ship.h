#pragma once
#include "Transport.h"
class Ship :
    public Transport
{
public:

    virtual double CalculateCost(Package& package);
    virtual unsigned CalculateDays(Package& package);
};

