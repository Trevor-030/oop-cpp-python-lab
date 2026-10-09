#ifndef TICKETCOMPONENT_H
#define TICKETCOMPONENT_H

#include <string>

using namespace std;

// Michael Agyenim Boateng Anning
// SRI.41.008.026.25

// 1. TICKET COMPONENT

// This is the parent class every fare calculation is built on. It only
// knows two things - the name of the component (like "Base Fare") and the
// number it works out (resultValue). Every subclass gets these for free
// and just adds whatever extra fields its own formula needs.


class TicketComponent
{
    public:
        // name gets passed straight through from whichever subclass is
        // being built, so the header/result printouts know what to call
        // themselves.
        TicketComponent(string name);

        // Prints a little "--- Component Name ---" banner. All four
        // subclasses just use this as-is, no need to rewrite it each time.
        void displayHeader();

        // Prints out resultValue with the given unit tacked on (GHS in
        // our case). Also shared by every subclass.
        void showResult(string unit);

    protected:
        // protected (not private) so the derived classes can set
        // resultValue themselves inside their own calculate() functions
        string componentName;
        double resultValue;

    private:
};

#endif // TICKETCOMPONENT_H
