#ifndef FINALTICKETCALCULATION_H
#define FINALTICKETCALCULATION_H

#include <TicketComponent.h>

// 4. FINAL TICKET CALCULATION
// Pulls together the base fare, the luggage charge and the discount
// into the amount the passenger actually has to pay. Still leans on
// TicketComponent for the header/result output, same as the others.

class FinalTicketCalculation : public TicketComponent
{
    public:
        // Passes "Final Ticket Price" up to the base class
        FinalTicketCalculation(double base, double luggage, double discount);

        // FinalFare = BaseFare + LuggageCharge - TotalDiscount
        void calculate();

    protected:

    private:
        // these three come from the other three calculations
        double baseFare;
        double luggageCharge;
        double totalDiscount;
};

#endif // FINALTICKETCALCULATION_H
