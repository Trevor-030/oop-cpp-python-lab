#ifndef BANK_H
#define BANK_H

#include <string>
#include <vector>
#include "BankAccount.h"

// (COMPOSITION) Owns a collection of BankAccount objects and routes every
// menu action to the right account by its account number.
class Bank
{
private:
    std::vector<BankAccount> accounts;

    // Searches accounts for a matching number; returns nullptr if not found.
    BankAccount *findAccount(int accNum);

public:
    // Checks whether a Customer ID is already in use.
    bool isCustomerIdTaken(int custId) const;

    // Creates an account; returns its number, or -1 if the Customer ID is taken.
    int createAccount(const std::string &name, int custId, double openingBalance, const std::string &pwd);

    void deposit(int accNum, double amount);
    void withdraw(int accNum, double amount);
    void checkBalance(int accNum);
    void changePassword(int accNum);
    void showTransactionLog(int accNum);
    void showAccountDetails(int accNum);

    // Transfers money between two accounts in one menu option.
    void transferFunds(int fromAccNum, int toAccNum, double amount);

    // Lists every account in the bank.
    void listAllAccounts() const;

    // Shows bank-wide totals (total accounts and funds held).
    void bankSummary() const;
};

#endif // BANK_H
