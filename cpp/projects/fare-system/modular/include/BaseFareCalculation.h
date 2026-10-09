#ifndef BASEFARECALCULATION_H
#define BASEFARECALCULATION_H

#include <TicketComponent.h>

// 1. BASE FARE CALCULATION
// Works out how much someone pays just for the distance travelled.
// Everything about printing the header/result is inherited from
// TicketComponent - this class only needs to know distance and rate.

class BaseFareCalculation : public TicketComponent
{
    public:
        // Passes "Base Fare" up to the base class so displayHeader() and
        // showResult() print the right label automatically
        BaseFareCalculation(double distance, double rate);

        // BaseFare = DistanceKm * RatePerKm
        void calculate();

        // So main() can grab the number afterwards and feed it into the
        // Final Ticket Price calculation
        double getValue() const;

    protected:

    private:
        // these two are specific to this class, not shared with the others
        double distanceKm;
        double ratePerKm;
};

#endif // BASEFARECALCULATION_H
