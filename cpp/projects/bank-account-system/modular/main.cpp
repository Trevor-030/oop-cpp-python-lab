/*
    BANK ACCOUNT MANAGEMENT SYSTEM (v3 - Multi-Account Edition)
    Group 8 - Object Oriented Programming Project

  * Michael Agyenim Boateng Anning  (SRI.41.008.026.25)
  * Christian David Takyi  (SRI.41.008.108.25)
  * Dawuda Kashafatu  (SRI.41.008.053.25)
  * Maame Esi Ohenewaa Andoh  (SRI.41.008.025.25)
  * Rita Awuviri  (SRI.41.008.039.25)
  * Oduro Appiah Kwaku  (SRI.41.008.089.25)
*/

#include "Console.h"
#include "Utils.h"
#include "Customer.h"
#include "BankAccount.h"
#include "Bank.h"
#include "Credits.h"

#include <iostream>

using namespace std;

// main() only asks what the user wants and hands the work to the Bank object.
int main()
{
    enableConsoleColours();
    showLoadingScreen();
    showWelcomeScreen();

    Bank bank;
    int choice;

    do
    {
        cout << "\n"
             << BOLD << CYAN << "==============================" << RESET << endl;
        cout << BOLD << CYAN << "         MAIN MENU" << RESET << endl;
        cout << BOLD << CYAN << "==============================" << RESET << endl;
        cout << endl;
        cout << CYAN << "[1]  Create New Account" << RESET << endl;
        cout << CYAN << "[2]  Deposit Funds" << RESET << endl;
        cout << CYAN << "[3]  Withdraw Funds" << RESET << endl;
        cout << CYAN << "[4]  Check Balance" << RESET << endl;
        cout << CYAN << "[5]  Change Password" << RESET << endl;
        cout << CYAN << "[6]  Transfer Funds" << RESET << endl;
        cout << CYAN << "[7]  Transaction History" << RESET << endl;
        cout << CYAN << "[8]  Account Details" << RESET << endl;
        cout << CYAN << "[9]  List Accounts" << RESET << endl;
        cout << CYAN << "[10] Bank Summary" << RESET << endl;
        cout << CYAN << "[11] Exit" << RESET << endl;
        cout << endl;
        cout << BOLD << CYAN << "==============================" << RESET << endl;

        choice = readInt("Enter your choice: ");

        if (choice == 1)
        {
            cout << BOLD << CYAN << "==========Create New Account==========" << RESET << endl;
            string name = readNonEmptyString("Enter Customer Name: ");

            int id;
            while (true)
            {
                id = readInt("Enter Customer ID: ");
                if (bank.isCustomerIdTaken(id))
                    cout << RED << "That Customer ID is already in use. Please enter a different one.\n"
                         << RESET;
                else
                    break;
            }

            double opening = readAmount("Enter Opening Balance: ");
            string pwd;
            while (true)
            {
                pwd = getMaskedPassword("Set Account Password: ");
                if (isValidPassword(pwd))
                    break;
                cout << RED << "Password must contain\n"
                     << "- Minimum 6 characters\n"
                     << "- At least one number\n"
                     << RESET;
            }

            int accNum = bank.createAccount(name, id, opening, pwd);
            cout << GREEN << "\n====================================" << RESET << endl;
            cout << GREEN << BOLD << "ACCOUNT CREATED SUCCESSFULLY" << RESET << endl;
            cout << GREEN << "====================================" << RESET << endl;
            cout << GREEN << "\nCustomer Name  : " << name << RESET << endl;
            cout << GREEN << "Customer ID    : " << id << RESET << endl;
            cout << GREEN << "Account Number : " << accNum << RESET << endl;
            cout << GREEN << "\nOpening Balance:" << RESET << endl;
            cout << GREEN << BOLD << "GHS " << formatAmount(opening) << RESET << endl;
        }
        else if (choice == 2)
        {
            int accNum = readInt("Enter Account Number: ");
            double amt = readAmount("Enter amount to deposit: ");
            bank.deposit(accNum, amt);
        }
        else if (choice == 3)
        {
            int accNum = readInt("Enter Account Number: ");
            double amt = readAmount("Enter amount to withdraw: ");
            bank.withdraw(accNum, amt);
        }
        else if (choice == 4)
        {
            int accNum = readInt("Enter Account Number: ");
            bank.checkBalance(accNum);
        }
        else if (choice == 5)
        {
            int accNum = readInt("Enter Account Number: ");
            bank.changePassword(accNum);
        }
        else if (choice == 6)
        {
            int from = readInt("Enter your Account Number: ");
            int to = readInt("Enter recipient's Account Number: ");
            double amt = readAmount("Enter amount to transfer: ");
            bank.transferFunds(from, to, amt);
        }
        else if (choice == 7)
        {
            int accNum = readInt("Enter Account Number: ");
            bank.showTransactionLog(accNum);
        }
        else if (choice == 8)
        {
            int accNum = readInt("Enter Account Number: ");
            bank.showAccountDetails(accNum);
        }
        else if (choice == 9)
        {
            bank.listAllAccounts();
        }
        else if (choice == 10)
        {
            bank.bankSummary();
        }
        else if (choice == 11)
        {
            cout << BOLD << CYAN << "==============================" << RESET << endl;
            cout << YELLOW << "Are you sure you want to exit?\n" << RESET;
            cout << CYAN << "[1] Yes\n[2] No\n" << RESET;
            int confirm = readInt("Enter your choice: ");
            if (confirm == 1)
            {
                cout << CYAN << "\nThank you for using the Bank Account Management System." << RESET << endl;
                break;
            }
            else
            {
                cout << CYAN << "\nReturning to the main menu..." << RESET << endl;
                continue;
            }
        }
        else if (choice == 777) // secret menu - intentionally not listed above
        {
            showCredits();
        }
        else
        {
            cout << RED << "Invalid choice. Please try again." << RESET << endl;
        }

    } while (true);

    return 0;
}
