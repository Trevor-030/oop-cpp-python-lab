#include <iostream>
#include <iomanip>
#include <string>

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
// DISPLAY MENU
// ============================================================

void displayMenu()
{
    cout << "\n";
    cout << "--------------------------------------------------"
         << endl;

    cout << "Welcome to the Ghana Railway Ticketing System"
         << endl;

    cout << "--------------------------------------------------"
         << endl;

    cout << "1. Calculate Base Fare" << endl;
    cout << "2. Calculate Excess Luggage Charge" << endl;
    cout << "3. Calculate Discount" << endl;
    cout << "4. Calculate Final Ticket Price" << endl;
    cout << "5. Exit" << endl;

    cout << "Enter your choice: ";
}


// ============================================================
// MAIN FUNCTION
// ============================================================

int main()
{
    int choice;
    char confirm = 'Y';

    do
    {
        displayMenu();
        cin >> choice;


        // ----------------------------------------------------
        // OPTION 1: BASE FARE
        // ----------------------------------------------------

        if (choice == 1)
        {
            double distanceKm;
            double ratePerKm;

            cout << "Enter distance travelled (km): ";
            cin >> distanceKm;

            // Validate distance
            while (distanceKm < 0)
            {
                cout << "Distance cannot be negative." << endl;
                cout << "Enter distance travelled (km): ";
                cin >> distanceKm;
            }

            cout << "Enter rate per km (GHS): ";
            cin >> ratePerKm;

            // Validate rate
            while (ratePerKm < 0)
            {
                cout << "Rate cannot be negative." << endl;
                cout << "Enter rate per km (GHS): ";
                cin >> ratePerKm;
            }

            // Create derived class object
            BaseFareCalculation baseFare(
                distanceKm,
                ratePerKm
            );

            // Calculate
            baseFare.calculate();

            // Inherited functions
            baseFare.displayHeader();
            baseFare.showResult("GHS");
        }


        // ----------------------------------------------------
        // OPTION 2: LUGGAGE CHARGE
        // ----------------------------------------------------

        else if (choice == 2)
        {
            double ratePerKg;
            double excessWeightKg;
            double chargeMultiplier;

            cout << "Enter rate per kg (GHS): ";
            cin >> ratePerKg;

            while (ratePerKg < 0)
            {
                cout << "Rate cannot be negative." << endl;
                cout << "Enter rate per kg (GHS): ";
                cin >> ratePerKg;
            }

            cout << "Enter excess luggage weight (kg): ";
            cin >> excessWeightKg;

            while (excessWeightKg < 0)
            {
                cout << "Weight cannot be negative." << endl;
                cout << "Enter excess luggage weight (kg): ";
                cin >> excessWeightKg;
            }

            cout << "Enter charge multiplier "
                 << "(1.5 standard / 2.0 priority): ";

            cin >> chargeMultiplier;

            while (chargeMultiplier <= 0)
            {
                cout << "Multiplier must be greater than 0."
                     << endl;

                cout << "Enter charge multiplier: ";
                cin >> chargeMultiplier;
            }

            // Create derived object
            LuggageChargeCalculation luggage(
                ratePerKg,
                excessWeightKg,
                chargeMultiplier
            );

            // Calculate
            luggage.calculate();

            // Inherited functions
            luggage.displayHeader();
            luggage.showResult("GHS");
        }


        // ----------------------------------------------------
        // OPTION 3: DISCOUNT
        // ----------------------------------------------------

        else if (choice == 3)
        {
            double fare;
            double studentDiscountRate;
            double loyaltyRate;

            cout << "Enter fare amount (GHS): ";
            cin >> fare;

            while (fare < 0)
            {
                cout << "Fare cannot be negative." << endl;
                cout << "Enter fare amount (GHS): ";
                cin >> fare;
            }

            cout << "Enter student discount rate "
                 << "(e.g., 0.10 for 10%): ";

            cin >> studentDiscountRate;

            // Validate student discount
            while (studentDiscountRate < 0 ||
                   studentDiscountRate > 1)
            {
                cout << "Discount rate must be between "
                     << "0 and 1." << endl;

                cout << "Enter student discount rate: ";
                cin >> studentDiscountRate;
            }

            cout << "Enter loyalty discount rate "
                 << "(e.g., 0.05 for 5%): ";

            cin >> loyaltyRate;

            // Validate loyalty discount
            while (loyaltyRate < 0 ||
                   loyaltyRate > 1)
            {
                cout << "Discount rate must be between "
                     << "0 and 1." << endl;

                cout << "Enter loyalty discount rate: ";
                cin >> loyaltyRate;
            }

            // Create derived object
            DiscountCalculation discount(
                fare,
                studentDiscountRate,
                loyaltyRate
            );

            // Calculate
            discount.calculate();

            // Inherited functions
            discount.displayHeader();
            discount.showResult("GHS");
        }


        // ----------------------------------------------------
        // OPTION 4: FINAL TICKET PRICE
        // ----------------------------------------------------

        else if (choice == 4)
        {
            double baseFare;
            double luggageCharge;
            double totalDiscount;

            cout << "Enter base fare (GHS): ";
            cin >> baseFare;

            while (baseFare < 0)
            {
                cout << "Base fare cannot be negative."
                     << endl;

                cout << "Enter base fare (GHS): ";
                cin >> baseFare;
            }

            cout << "Enter luggage charge (GHS): ";
            cin >> luggageCharge;

            while (luggageCharge < 0)
            {
                cout << "Luggage charge cannot be negative."
                     << endl;

                cout << "Enter luggage charge (GHS): ";
                cin >> luggageCharge;
            }

            cout << "Enter total discount (GHS): ";
            cin >> totalDiscount;

            while (totalDiscount < 0)
            {
                cout << "Discount cannot be negative."
                     << endl;

                cout << "Enter total discount (GHS): ";
                cin >> totalDiscount;
            }

            // Create derived object
            FinalTicketCalculation finalTicket(
                baseFare,
                luggageCharge,
                totalDiscount
            );

            // Calculate
            finalTicket.calculate();

            // Inherited functions
            finalTicket.displayHeader();
            finalTicket.showResult("GHS");
        }


        // ----------------------------------------------------
        // OPTION 5: EXIT
        // ----------------------------------------------------

        else if (choice == 5)
        {
            cout << "\nThank you for using the "
                 << "Ghana Railway Ticketing System!"
                 << endl;

            break;
        }


        // ----------------------------------------------------
        // INVALID CHOICE
        // ----------------------------------------------------

        else
        {
            cout << "Invalid choice. Please select "
                 << "1 - 5." << endl;
        }


        // Ask whether user wants another calculation
        if (choice != 5)
        {
            cout << "\nDo you want to perform another "
                 << "calculation? (Y/N): ";

            cin >> confirm;

            if (confirm == 'N' || confirm == 'n')
            {
                cout << "\nThank you for using the "
                     << "Ghana Railway Ticketing System!"
                     << endl;

                break;
            }
        }

    } while (true);


    return 0;
}
