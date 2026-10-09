#ifndef LUGGAGECHARGECALCULATION_H
#define LUGGAGECHARGECALCULATION_H

#include <TicketComponent.h>

// 2. LUGGAGE CHARGE CALCULATION
// Handles the surcharge for luggage over the free weight limit.
// Same deal as BaseFareCalculation - inherits the header/result display,
// only adds what's specific to working out the luggage fee.

class LuggageChargeCalculation : public TicketComponent
{
    public:
        // Sends "Excess Luggage Charge" up to the base class constructor
        LuggageChargeCalculation(double rate, double weight, double multiplier);

        // ExcessLuggageCharge = RatePerKg * ExcessWeightKg * ChargeMultiplier
        void calculate();

        double getValue() const;

    protected:

    private:
        // specific to this class only
        double ratePerKg;
        double excessWeightKg;
        double chargeMultiplier;   // 1.5 for standard excess, 2.0 for priority/express
};

#endif // LUGGAGECHARGECALCULATION_H
