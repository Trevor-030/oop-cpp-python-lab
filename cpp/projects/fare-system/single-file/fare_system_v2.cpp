#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cctype>

using namespace std;


// Michael Agyenim Boateng Anning
// SRI.41.008.026.25

class TicketComponent
{
protected:
    string componentName;
    double resultValue;

public:

    // Base class constructor
    TicketComponent(string name) : componentName(name), resultValue(0.0) {}
    // Common function inherited by all derived classes
    void displayHeader()
    {
        cout << "\n--- " << componentName << " ---" << endl;
    }

    // Common function inherited by all derived classes
    
    void showResult(string unit)
    {
        cout << fixed << setprecision(2);
        cout << "Result: " << resultValue << " " << unit << endl;
    }
};


// ============================================================
// 1. BASE FARE CALCULATION
// ============================================================

class BaseFareCalculation : public TicketComponent
{
private:
    double distanceKm;
    double ratePerKm;

public:

    // Constructor passes component name to base class
    BaseFareCalculation(double distance, double rate)
        : TicketComponent("Base Fare"), distanceKm(distance), ratePerKm(rate) {}

    // Specific calculation for Base Fare
    void calculate()
    {
        resultValue = distanceKm * ratePerKm;
    }

    // Lets main() read back the result (e.g. to feed into Final Ticket Price)
    double getValue() const { return resultValue; }
};


// ============================================================
// 2. LUGGAGE CHARGE CALCULATION
// ============================================================

class LuggageChargeCalculation : public TicketComponent
{
private:
    double ratePerKg;
    double excessWeightKg;
    double chargeMultiplier;

public:

    // Constructor passes component name to base class
    LuggageChargeCalculation(double rate, double weight, double multiplier)
        : TicketComponent("Excess Luggage Charge"),
          ratePerKg(rate), excessWeightKg(weight), chargeMultiplier(multiplier) {}

    // Specific calculation for luggage
    void calculate()
    {
        resultValue = ratePerKg * excessWeightKg * chargeMultiplier;
    }

    double getValue() const { return resultValue; }
};


// ============================================================
// 3. DISCOUNT CALCULATION
// ============================================================

class DiscountCalculation : public TicketComponent
{
private:
    double fare;
    double studentDiscountRate;
    double loyaltyRate;

public:

    // Constructor passes component name to base class
    DiscountCalculation(double fareAmount, double studentRate, double loyalty)
        : TicketComponent("Ticket Discount"),
          fare(fareAmount), studentDiscountRate(studentRate), loyaltyRate(loyalty) {}

    // Specific calculation for discount
    void calculate()
    {
        resultValue =
            (studentDiscountRate * fare) +
            (loyaltyRate * fare);
    }

    double getValue() const { return resultValue; }
};


// ============================================================
// 4. FINAL TICKET CALCULATION
// ============================================================

class FinalTicketCalculation : public TicketComponent
{
private:
    double baseFare;
    double luggageCharge;
    double totalDiscount;

public:

    // Constructor passes component name to base class
    FinalTicketCalculation(double base, double luggage, double discount)
        : TicketComponent("Final Ticket Price"),
          baseFare(base), luggageCharge(luggage), totalDiscount(discount) {}

    // Specific calculation for final ticket price
    void calculate()
    {
        resultValue =
            baseFare + luggageCharge - totalDiscount;
    }
};


// ============================================================
// INPUT HELPERS
// ============================================================

// Reads a double that cannot be negative, re-prompting until valid.
double readNonNegativeDouble(const string &prompt)
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

        if (value < 0)
        {
            cout << "  Value cannot be negative. Try again." << endl;
            continue;
        }

        return value;
    }
}

// Reads a rate that must be between 0 and 1 (e.g. discount rates).
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


// ============================================================
// DISPLAY MENU
// ============================================================

void displayMenu()
{
    cout << "\n------------------------------------------------------------------\n";
    cout << "1. Calculate Base Fare\n";
    cout << "2. Calculate Excess Luggage Charge\n";
    cout << "3. Calculate Discount\n";
    cout << "4. Calculate Final Ticket Price\n";
    cout << "5. Exit\n";
}


// ============================================================
// MAIN FUNCTION
// ============================================================

int main()
{
    int choice;
    char confirm = 'Y';

    // Remembered between calculations so option 4 can reuse the most
    // recent Base Fare / Luggage Charge / Discount results.
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
                baseFare.calculate();          // own function
                baseFare.displayHeader();      // inherited
                baseFare.showResult("GHS");    // inherited

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
                luggage.calculate();
                luggage.displayHeader();
                luggage.showResult("GHS");

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
                discount.calculate();
                discount.displayHeader();
                discount.showResult("GHS");

                lastDiscount = discount.getValue();
                break;
            }
            case 4:
            {
                // ---- FinalTicketCalculation ----
                // Offer to reuse the most recently calculated values, or let
                // the user type in fresh figures.
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
                finalTicket.calculate();
                finalTicket.displayHeader();
                finalTicket.showResult("GHS");
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
