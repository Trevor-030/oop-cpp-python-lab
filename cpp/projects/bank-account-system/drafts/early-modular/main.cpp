#include <iostream>
#include <iomanip>
#include <sstream>
#include "Customer.h"
#include "BankAccount.h"
using namespace std;

// member initialization list
/*
: customer(c)

This is called the member initializer list.

Instead of assigning customer inside the constructor body, it initializes it directly.

It is equivalent to saying:
*/

string formatAmount(double amount) {
    ostringstream oss;
    oss << fixed << setprecision(2) << amount;
    return oss.str();
}

int main() {
    string name, password, newPassword;
    int id, accountNumber;
    double balance, amount;
    int choice;

    cout << "Enter Customer Name: " << endl;
    getline(cin, name);

    cout << "Enter Customer ID: " << endl;
    cin >> id;

    cout << "Enter Account Number: " << endl;
    cin >> accountNumber;

    cout << "Enter Initial Balance: " << endl;
    cin >> balance;

    cout << "Enter Password: " << endl;
    cin >> password;

    Customer customer(name, id);
    BankAccount account(customer, accountNumber, balance, password);

    do {
        cout << "\n==========Bank Account Menu==========" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Change Password" << endl;
        cout << "5. Display Transaction Log" << endl;
        cout << "6. Display Account Details" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter amount to deposit: ";
            cin >> amount;
            account.deposit(amount);
        }
        else if (choice == 2) {
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            account.withdraw(amount);
        }
        else if (choice == 3) {
            account.checkBalance();
        }
        else if (choice == 4) {
            cout << "Enter new password: ";
            cin >> newPassword;
            account.changePassword(newPassword);
        }
        else if (choice == 5) {
            account.displayTransactionLog();
        }
        else if (choice == 6) {
            displayAccountDetails(account);
        }
        else if (choice == 7) {
            cout << "Exiting..." << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
