#ifndef DISCOUNTCALCULATION_H
#define DISCOUNTCALCULATION_H

#include <TicketComponent.h>

// 3. DISCOUNT CALCULATION
// Adds up the student discount and the loyalty discount into one
// total discount figure. Again, header/result printing is inherited,
// this class just does the discount maths.

class DiscountCalculation : public TicketComponent
{
    public:
        // Passes "Ticket Discount" up to the base class
        DiscountCalculation(double fareAmount, double studentRate, double loyalty);

        // TotalDiscount = (StudentDiscountRate * Fare) + (LoyaltyRate * Fare)
        void calculate();

        double getValue() const;

    protected:

    private:
        // only needed here, not shared with the other calculations
        double fare;
        double studentDiscountRate;   // typically 0.10 for students
        double loyaltyRate;           // depends on how often the customer travels
};

#endif // DISCOUNTCALCULATION_H
