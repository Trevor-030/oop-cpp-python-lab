#include "BaseFareCalculation.h"

// Initializer list sends "Base Fare" up to TicketComponent's constructor,
// then sets our own distanceKm/ratePerKm
BaseFareCalculation::BaseFareCalculation(double distance, double rate)
    : TicketComponent("Base Fare"), distanceKm(distance), ratePerKm(rate)
{
    //ctor
}

// This is the only formula this class cares about
void BaseFareCalculation::calculate()
{
    resultValue = distanceKm * ratePerKm;
}

double BaseFareCalculation::getValue() const
{
    return resultValue;
}
