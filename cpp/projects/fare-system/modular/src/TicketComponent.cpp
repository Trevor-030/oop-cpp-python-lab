#include "TicketComponent.h"
#include <iostream>
#include <iomanip>

// Just stashes the name and zeroes out the result until calculate() runs.
TicketComponent::TicketComponent(string name)
    : componentName(name), resultValue(0.0)
{
    //ctor
}

void TicketComponent::displayHeader()
{
    cout << "\n--- " << componentName << " ---" << endl;
}

void TicketComponent::showResult(string unit)
{
    // 2 decimal places since we're dealing with money (GHS)
    cout << fixed << setprecision(2);
    cout << "Result: " << resultValue << " " << unit << endl;
}
