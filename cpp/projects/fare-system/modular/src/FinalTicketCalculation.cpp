#include "FinalTicketCalculation.h"

// Initializer list sends "Final Ticket Price" to the base class, then
// stores the three amounts that were passed in from main()
FinalTicketCalculation::FinalTicketCalculation(double base, double luggage, double discount)
    : TicketComponent("Final Ticket Price"),
      baseFare(base), luggageCharge(luggage), totalDiscount(discount)
{
    //ctor
}

// Add the fare and luggage charge, then take off the discount
void FinalTicketCalculation::calculate()
{
    resultValue =
        baseFare + luggageCharge - totalDiscount;
}
