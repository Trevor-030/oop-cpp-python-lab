#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cctype>

#include "TicketComponent.h"
#include "BaseFareCalculation.h"
#include "LuggageChargeCalculation.h"
#include "DiscountCalculation.h"
#include "FinalTicketCalculation.h"

using namespace std;

// Michael Agyenim Boateng Anning
// SRI.41.008.026.25



// INPUT HELPERS


// Keeps asking until the user gives a number that isn't negative.
// Used for things like distance and weight which can never go below 0.
double readNonNegativeDouble(const string &prompt)
{
    double value;
    while (true)
    {
        cout << prompt;
        cin >> value;

        if (cin.fail())
        {
            // user typed letters or something else that isn't a number,
            // so clear the error flag and flush the bad input out
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  Invalid input. Please enter a numeric value." << endl;
            continue;
        }

        if (value < 0)
        {
            cout << "  Value cannot be negative. Try again." << endl;
            continue;
        }

        return value;
    }
}

// Same idea, but for rates like the student/loyalty discounts, which only
// make sense as a fraction between 0 and 1 (0.10 = 10%, etc.)
double readRateBetweenZeroAndOne(const string &prompt)
{
    double value;
    while (true)
    {
        cout << prompt;
        cin >> value;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  Invalid input. Please enter a numeric value." << endl;
            continue;
        }

        if (value < 0.0 || value > 1.0)
        {
            cout << "  Rate must be between 0 and 1 (e.g. 0.10 for 10%). Try again." << endl;
            continue;
        }

        return value;
    }
}



// DISPLAY MENU


void displayMenu()
{
    cout << "\n------------------------------------------------------------------\n";
    cout << "1. Calculate Base Fare\n";
    cout << "2. Calculate Excess Luggage Charge\n";
    cout << "3. Calculate Discount\n";
    cout << "4. Calculate Final Ticket Price\n";
    cout << "5. Exit\n";
}


// MAIN FUNCTION

int main()
{
    int choice;
    char confirm = 'Y';

    // Keep the last calculated values around so option 4 (Final Ticket
    // Price) can offer to reuse them instead of making the user retype
    // numbers they already entered earlier in the same session.
    double lastBaseFare = 0.0;
    double lastLuggageCharge = 0.0;
    double lastDiscount = 0.0;

    cout << "Welcome to the Ghana Railway Ticketing System\n";

    do
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  Invalid choice. Please enter a number between 1 and 5.\n";
            continue;
        }

        switch (choice)
        {
            case 1:
            {
                // ---- BaseFareCalculation ----
                double distance = readNonNegativeDouble("Enter distance travelled (km): ");
                double rate     = readNonNegativeDouble("Enter rate per km (GHS): ");

                BaseFareCalculation baseFare(distance, rate);
                baseFare.calculate();          // this one's specific to BaseFareCalculation
                baseFare.displayHeader();      // inherited from TicketComponent
                baseFare.showResult("GHS");    // inherited from TicketComponent

                lastBaseFare = baseFare.getValue();
                break;
            }
            case 2:
            {
                // ---- LuggageChargeCalculation ----
                double rate       = readNonNegativeDouble("Enter rate per kg (GHS): ");
                double weight     = readNonNegativeDouble("Enter excess luggage weight (kg): ");
                double multiplier = readNonNegativeDouble(
                    "Enter charge multiplier (1.5 standard / 2.0 priority): ");

                LuggageChargeCalculation luggage(rate, weight, multiplier);
                luggage.calculate();       // specific to this class
                luggage.displayHeader();   // inherited
                luggage.showResult("GHS"); // inherited

                lastLuggageCharge = luggage.getValue();
                break;
            }
            case 3:
            {
                // ---- DiscountCalculation ----
                double fare = readNonNegativeDouble("Enter fare amount (GHS): ");
                double studentRate = readRateBetweenZeroAndOne(
                    "Enter student discount rate (e.g., 0.10 for 10%): ");
                double loyaltyRate = readRateBetweenZeroAndOne(
                    "Enter loyalty discount rate (e.g., 0.05 for 5%): ");

                DiscountCalculation discount(fare, studentRate, loyaltyRate);
                discount.calculate();       // specific to this class
                discount.displayHeader();   // inherited
                discount.showResult("GHS"); // inherited

                lastDiscount = discount.getValue();
                break;
            }
            case 4:
            {
                // ---- FinalTicketCalculation ----
                // Rather than force the user to retype numbers they've
                // already entered above, offer to reuse whatever the last
                // Base Fare / Luggage Charge / Discount worked out to be.
                cout << "Use most recent Base Fare (" << fixed << setprecision(2)
                     << lastBaseFare << " GHS), Luggage Charge ("
                     << lastLuggageCharge << " GHS) and Discount ("
                     << lastDiscount << " GHS)? (Y/N): ";
                char useLast;
                cin >> useLast;

                double base, luggage, discount;
                if (toupper(useLast) == 'Y')
                {
                    base = lastBaseFare;
                    luggage = lastLuggageCharge;
                    discount = lastDiscount;
                }
                else
                {
                    base     = readNonNegativeDouble("Enter base fare (GHS): ");
                    luggage  = readNonNegativeDouble("Enter luggage charge (GHS): ");
                    discount = readNonNegativeDouble("Enter total discount (GHS): ");
                }

                FinalTicketCalculation finalTicket(base, luggage, discount);
                finalTicket.calculate();       // specific to this class
                finalTicket.displayHeader();   // inherited
                finalTicket.showResult("GHS"); // inherited
                break;
            }
            case 5:
                cout << "\nThank you for using the Ghana Railway Ticketing System!\n";
                return 0;
            default:
                cout << "  Invalid choice. Please select an option between 1 and 5.\n";
                continue;
        }

        cout << "\nDo you want to perform another calculation? (Y/N): ";
        cin >> confirm;

    } while (toupper(confirm) == 'Y');

    cout << "\nThank you for using the Ghana Railway Ticketing System!\n";
    return 0;
}
