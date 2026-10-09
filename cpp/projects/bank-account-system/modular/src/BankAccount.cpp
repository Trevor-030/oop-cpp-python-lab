#include "BankAccount.h"
#include "Console.h"
#include "Utils.h"

#include <iostream>

using namespace std;

int BankAccount::nextAccountNumber = 1001;

void BankAccount::log(const string &type, const string &detail)
{
    transactionLog.push_back("[" + getTimestamp() + "] " + type + "|" + detail);
}

BankAccount::BankAccount(Customer c, double openingBalance, string pwd)
    : customer(c), accountNumber(nextAccountNumber++),
      balance(openingBalance), password(pwd)
{
    log("Account Opened", "Opening Balance: " + formatGHS(balance));
}

int BankAccount::getAccountNumber() const { return accountNumber; }
double BankAccount::getBalance() const { return balance; }
string BankAccount::getCustomerName() const { return customer.getName(); }
int BankAccount::getCustomerId() const { return customer.getId(); }
bool BankAccount::verifyPassword(const string &pwd) const { return pwd == password; }

void BankAccount::deposit(double amount)
{
    cout << BOLD << CYAN << "==========Deposit Transaction==========" << RESET << endl;
    string entered = getMaskedPassword("Enter Password: ");
    if (!verifyPassword(entered))
    {
        cout << RED << "Incorrect Password. Transaction Failed." << RESET << endl;
        return;
    }
    balance += amount;
    log("Deposit", formatGHS(amount));
    cout << GREEN << "Deposited: " << formatGHS(amount) << RESET << endl;
    cout << GREEN << "New Balance: " << formatGHS(balance) << RESET << endl;
}

void BankAccount::withdraw(double amount)
{
    cout << BOLD << CYAN << "==========Withdraw Transaction==========" << RESET << endl;
    string entered = getMaskedPassword("Enter Password: ");
    if (!verifyPassword(entered))
    {
        cout << RED << "Incorrect Password. Transaction Failed." << RESET << endl;
        return;
    }
    if (amount > balance)
    {
        cout << RED << "Insufficient funds." << RESET << endl;
        return;
    }
    balance -= amount;
    log("Withdrawal", formatGHS(amount));
    cout << GREEN << "Withdrew: " << formatGHS(amount) << RESET << endl;
    cout << GREEN << "New Balance: " << formatGHS(balance) << RESET << endl;
}

void BankAccount::changePassword()
{
    cout << BOLD << CYAN << "==========Change Password==========" << RESET << endl;
    string current = getMaskedPassword("Enter Current Password: ");
    if (!verifyPassword(current))
    {
        cout << RED << "Incorrect Password. Password change failed." << RESET << endl;
        return;
    }
    string newPwd = getMaskedPassword("Enter New Password: ");
    password = newPwd;
    log("Password Changed", "Account password updated.");
    cout << GREEN << "Password changed successfully." << RESET << endl;
}

void BankAccount::checkBalance()
{
    cout << BOLD << CYAN << "==========Balance Check==========" << RESET << endl;
    string entered = getMaskedPassword("Enter Password: ");
    if (!verifyPassword(entered))
    {
        cout << RED << "Incorrect Password. Balance check failed." << RESET << endl;
        return;
    }
    cout << GREEN << "Current Balance: " << formatGHS(balance) << RESET << endl;
}

void BankAccount::displayTransactionLog() const
{
    cout << BOLD << CYAN << "=========================================" << RESET << endl;
    cout << BOLD << CYAN << "Transaction History" << RESET << endl;
    cout << BOLD << CYAN << "=========================================" << RESET << endl;
    cout << endl;
    if (transactionLog.empty())
    {
        cout << YELLOW << "No transactions yet." << RESET << endl;
    }
    else
    {
        for (size_t i = 0; i < transactionLog.size(); ++i)
        {
            string entry = transactionLog[i];
            size_t bar = entry.find("] ");
            string stamp = entry.substr(0, bar + 1);
            string rest = entry.substr(bar + 2);
            size_t sep = rest.find('|');
            string type = rest.substr(0, sep);
            string detail = rest.substr(sep + 1);

            cout << "[" << stamp << "\n";
            cout << GREEN << type << RESET << "\n";
            cout << "Amount: " << detail << "\n";
            cout << "-----------------------------------------\n";
        }
    }
}

void BankAccount::receiveInternal(double amount)
{
    balance += amount;
    log("Transfer Received", formatGHS(amount));
}

void BankAccount::sendInternal(double amount)
{
    balance -= amount;
    log("Transfer Sent", formatGHS(amount));
}

void displayAccountDetails(const BankAccount &account)
{
    cout << BOLD << CYAN << "==========Account Details==========" << RESET << endl;
    account.customer.displayCustomer();
    cout << "Account Number : " << account.accountNumber << endl;
    cout << "Current Balance: " << formatGHS(account.balance) << endl;
    cout << "Transactions   : " << account.transactionLog.size() << endl;
}
