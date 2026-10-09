#include "LuggageChargeCalculation.h"

// Initializer list passes "Excess Luggage Charge" to the base class,
// then sets the fields that belong only to this calculation
LuggageChargeCalculation::LuggageChargeCalculation(double rate, double weight, double multiplier)
    : TicketComponent("Excess Luggage Charge"),
      ratePerKg(rate), excessWeightKg(weight), chargeMultiplier(multiplier)
{
    //ctor
}

// rate * weight * whichever multiplier was passed in (standard/priority)
void LuggageChargeCalculation::calculate()
{
    resultValue = ratePerKg * excessWeightKg * chargeMultiplier;
}

double LuggageChargeCalculation::getValue() const
{
    return resultValue;
}
