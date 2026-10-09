#include "DiscountCalculation.h"

// Initializer list sends "Ticket Discount" to the base class, then stores
// the fare and the two discount rates we'll need in calculate()
DiscountCalculation::DiscountCalculation(double fareAmount, double studentRate, double loyalty)
    : TicketComponent("Ticket Discount"),
      fare(fareAmount), studentDiscountRate(studentRate), loyaltyRate(loyalty)
{
    //ctor
}

// Just add both discount amounts together
void DiscountCalculation::calculate()
{
    resultValue =
        (studentDiscountRate * fare) +
        (loyaltyRate * fare);
}

double DiscountCalculation::getValue() const
{
    return resultValue;
}
