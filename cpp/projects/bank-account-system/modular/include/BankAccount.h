#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <vector>
#include "Customer.h"

// Stores one account: balance, password, and transaction history.
class BankAccount
{
private:
    Customer customer;
    int accountNumber;
    double balance;
    std::string password;
    std::vector<std::string> transactionLog;

    // STATIC MEMBER: shared counter that generates unique account numbers.
    static int nextAccountNumber;

    // Stores a timestamped transaction log entry (format: "type|detail").
    void log(const std::string &type, const std::string &detail);

public:
    BankAccount(Customer c, double openingBalance, std::string pwd);

    int getAccountNumber() const;
    double getBalance() const;
    std::string getCustomerName() const;
    int getCustomerId() const;
    bool verifyPassword(const std::string &pwd) const;

    void deposit(double amount);
    void withdraw(double amount);
    void changePassword();
    void checkBalance();
    void displayTransactionLog() const;

    // Internal transfer helpers (no password re-check; used by Bank::transferFunds).
    void receiveInternal(double amount);
    void sendInternal(double amount);

    friend void displayAccountDetails(const BankAccount &account);
};

// FRIEND FUNCTION: accesses private members of BankAccount without being a member.
void displayAccountDetails(const BankAccount &account);

#endif // BANKACCOUNT_H
