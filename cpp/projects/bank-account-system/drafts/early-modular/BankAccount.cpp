#include "BankAccount.h"
#include <iostream>
#include <string>
using namespace std;

// Forward declaration: formatAmount() is defined in main.cpp.
// No header for it since it lives directly alongside main().
string formatAmount(double amount);

BankAccount::BankAccount(Customer c, int acc, double bal, string pwd) : customer(c) {
    accountNumber = acc;
    balance = bal;
    password = pwd;
    cout << "\nBank Account Created\n";
}

BankAccount::~BankAccount() {
    cout << "\nBank Account " << accountNumber << " Closed\n";
}

void BankAccount::deposit(double amount) {
    cout << "==========Deposit Transaction==========" << endl;
    cout << "Enter Password: " << endl;
    cin >> inputPassword;
    if (inputPassword != password) {
        cout << "Incorrect Password. Transaction Failed." << endl;
    }
    else {
        balance += amount;
        cout << "Deposited: " << formatAmount(amount) << endl;
        cout << "New Balance: " << formatAmount(balance) << " only" << endl;

        transactionLog.push_back("Deposited: " + formatAmount(amount) + ", New Balance: " + formatAmount(balance));
    }
}

void BankAccount::withdraw(double amount) {
    cout << "==========Withdraw Transaction==========" << endl;
    cout << "Enter Password: " << endl;
    cin >> inputPassword;
    if (inputPassword != password) {
        cout << "Incorrect Password. Transaction Failed." << endl;
    }
    else {
        if (amount > balance) {
            cout << "Insufficient funds." << endl;
        } else {
            balance -= amount;
            cout << "Withdrew: " << formatAmount(amount) << endl;
            cout << "New Balance: " << formatAmount(balance) << " only" << endl;
            transactionLog.push_back("Withdrew: " + formatAmount(amount) + ", New Balance: " + formatAmount(balance));
        }
    }
}

void BankAccount::changePassword(string newPassword) {
    cout << "==========Change Password==========" << endl;
    cout << "Enter Current Password: " << endl;
    cin >> inputPassword;
    if (inputPassword != password) {
        cout << "Incorrect Password. Password change failed." << endl;
    }
    else {
        password = newPassword;
        cout << "Password changed successfully." << endl;
    }
}

void BankAccount::checkBalance() {
    cout << "==========Balance Check==========" << endl;
    cout << "Enter Password: " << endl;
    cin >> inputPassword;
    if (inputPassword != password) {
        cout << "Incorrect Password. Balance check failed." << endl;
    }
    else {
        cout << "Current Balance(GHS): " << formatAmount(balance) << " only" << endl;
    }
}

void BankAccount::displayTransactionLog() {
    cout << "==========Transaction Log==========" << endl;
    if (transactionLog.empty()) {
        cout << "No transactions yet." << endl;
    }
    else {
        for (size_t i = 0; i < transactionLog.size(); ++i) {
            cout << i + 1 << ". " << transactionLog[i] << endl;
        }
    }
}

void displayAccountDetails(BankAccount &account) {
    cout << "==========Account Details==========" << endl;
    account.customer.displayCustomer();
    cout << "Account Number: " << account.accountNumber << endl;
    cout << "Total Transactions: " << account.transactionLog.size() << endl;
}
