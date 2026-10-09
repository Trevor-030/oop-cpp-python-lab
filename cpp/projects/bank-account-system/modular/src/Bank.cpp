#include "Bank.h"
#include "Console.h"
#include "Utils.h"

#include <iostream>

using namespace std;

BankAccount *Bank::findAccount(int accNum)
{
    for (auto &acc : accounts)
        if (acc.getAccountNumber() == accNum)
            return &acc;
    return nullptr;
}

bool Bank::isCustomerIdTaken(int custId) const
{
    for (const auto &acc : accounts)
        if (acc.getCustomerId() == custId)
            return true;
    return false;
}

int Bank::createAccount(const string &name, int custId, double openingBalance, const string &pwd)
{
    if (isCustomerIdTaken(custId))
        return -1;
    Customer c(name, custId);
    accounts.push_back(BankAccount(c, openingBalance, pwd));
    return accounts.back().getAccountNumber();
}

void Bank::deposit(int accNum, double amount)
{
    BankAccount *acc = findAccount(accNum);
    if (!acc)
    {
        cout << RED << "Account not found." << RESET << endl;
        return;
    }
    acc->deposit(amount);
}

void Bank::withdraw(int accNum, double amount)
{
    BankAccount *acc = findAccount(accNum);
    if (!acc)
    {
        cout << RED << "Account not found." << RESET << endl;
        return;
    }
    acc->withdraw(amount);
}

void Bank::checkBalance(int accNum)
{
    BankAccount *acc = findAccount(accNum);
    if (!acc)
    {
        cout << RED << "Account not found." << RESET << endl;
        return;
    }
    acc->checkBalance();
}

void Bank::changePassword(int accNum)
{
    BankAccount *acc = findAccount(accNum);
    if (!acc)
    {
        cout << RED << "Account not found." << RESET << endl;
        return;
    }
    acc->changePassword();
}

void Bank::showTransactionLog(int accNum)
{
    BankAccount *acc = findAccount(accNum);
    if (!acc)
    {
        cout << RED << "Account not found." << RESET << endl;
        return;
    }
    acc->displayTransactionLog();
}

void Bank::showAccountDetails(int accNum)
{
    BankAccount *acc = findAccount(accNum);
    if (!acc)
    {
        cout << RED << "Account not found." << RESET << endl;
        return;
    }
    displayAccountDetails(*acc);
}

void Bank::transferFunds(int fromAccNum, int toAccNum, double amount)
{
    cout << BOLD << CYAN << "==========Transfer Funds==========" << RESET << endl;
    if (fromAccNum == toAccNum)
    {
        cout << RED << "Cannot transfer to the same account." << RESET << endl;
        return;
    }
    BankAccount *from = findAccount(fromAccNum);
    BankAccount *to = findAccount(toAccNum);
    if (!from || !to)
    {
        cout << RED << "One or both account numbers were not found." << RESET << endl;
        return;
    }

    string entered = getMaskedPassword("Enter Password for Account #" + to_string(fromAccNum) + ": ");
    if (!from->verifyPassword(entered))
    {
        cout << RED << "Incorrect Password. Transfer Failed." << RESET << endl;
        return;
    }
    if (amount > from->getBalance())
    {
        cout << RED << "Insufficient funds." << RESET << endl;
        return;
    }

    // Balance is checked BEFORE any money moves.
    from->sendInternal(amount);
    to->receiveInternal(amount);
    cout << GREEN << "Transferred " << formatGHS(amount) << " from Account #" << fromAccNum
         << " to Account #" << toAccNum << "." << RESET << endl;
}

void Bank::listAllAccounts() const
{
    cout << BOLD << CYAN << "==========All Accounts==========" << RESET << endl;
    if (accounts.empty())
    {
        cout << YELLOW << "No accounts have been created yet." << RESET << endl;
        return;
    }
    for (const auto &acc : accounts)
    {
        cout << "Account #" << acc.getAccountNumber()
             << "  |  " << acc.getCustomerName()
             << "  |  Balance: " << formatGHS(acc.getBalance()) << endl;
    }
}

void Bank::bankSummary() const
{
    double totalFunds = 0.0;
    for (const auto &acc : accounts)
        totalFunds += acc.getBalance();

    cout << BOLD << CYAN << "==========Bank Summary==========" << RESET << endl;
    cout << GREEN << "Total Accounts   : " << accounts.size() << RESET << endl;
    cout << GREEN << "Total Funds Held : " << formatGHS(totalFunds) << RESET << endl;
}
