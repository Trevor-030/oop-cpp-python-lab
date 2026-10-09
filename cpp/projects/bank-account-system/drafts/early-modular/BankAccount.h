#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <vector>
#include "Customer.h"

class BankAccount {
    private:
        Customer customer;
        int accountNumber;
        double balance;
        std::string password;
        std::string inputPassword;
        std::vector<std::string> transactionLog;

    public:
        BankAccount(Customer c, int acc, double bal, std::string pwd);
        ~BankAccount();

        void deposit(double amount);
        void withdraw(double amount);
        void changePassword(std::string newPassword);
        void checkBalance();
        void displayTransactionLog();

        // Friend function: not a member, but granted access to private data
        friend void displayAccountDetails(BankAccount &account);
};

// Declared here (outside the class) since it's a friend, not a member
void displayAccountDetails(BankAccount &account);

#endif // BANKACCOUNT_H
