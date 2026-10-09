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

// Console and platform headers.

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <limits>
#include <thread>
#include <chrono>

// Password masking needs different tools on Windows vs Linux/Mac.
#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

using namespace std;

// CONSOLE COLOURS
// ANSI colour codes for clearer output (headers, prompts, success, errors).
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string CYAN = "\033[36m";
const string BOLD = "\033[1m";

#ifdef _WIN32
void enableConsoleColours()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hOut, &mode);
    SetConsoleMode(hOut, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}
#else
void enableConsoleColours()
{
}
#endif

// STARTUP LOADING SCREEN
void showLoadingScreen()
{
    cout << CYAN << BOLD;
    cout << "\n  ============================================\n";
    cout << "         BANK ACCOUNT MANAGEMENT SYSTEM\n";
    cout << "                   Group 8\n";
    cout << "  ============================================\n";
    cout << RESET << "\n";

    cout << YELLOW << "  Loading Banking Services" << RESET;
    for (int i = 0; i < 3; i++)
    {
        this_thread::sleep_for(chrono::milliseconds(350));
        cout << YELLOW << "." << RESET << flush;
    }
    cout << "\n\n";

    const int barWidth = 30;
    for (int i = 0; i <= barWidth; i++)
    {
        cout << "\r  [" << GREEN;
        for (int j = 0; j < barWidth; j++)
            cout << (j < i ? "#" : " ");
        cout << RESET << "] " << (i * 100 / barWidth) << "%  " << flush;
        this_thread::sleep_for(chrono::milliseconds(25));
    }
    cout << endl;

    cout << GREEN << BOLD << "\n  System Ready." << RESET << endl;
    cout << YELLOW << "  Press Enter to Continue..." << RESET << endl;
    cin.get();
    this_thread::sleep_for(chrono::milliseconds(200));

    cout << "\033[2J\033[1;1H"; // clear the screen before the real menu appears
}

// WELCOME SCREEN
void showWelcomeScreen()
{
    cout << BOLD << CYAN;
    cout << "==========================================\n";
    cout << "      BANK ACCOUNT MANAGEMENT SYSTEM\n";
    cout << "==========================================\n"
         << RESET << endl;
    cout << "Version 3.0\n";
    cout << "Object Oriented Programming Project\n\n";
    cout << "Developed by:\n";
    cout << "Group 8\n\n";
    cout << YELLOW << "Press ENTER to continue..." << RESET;
    cin.get();
    cout << "\033[2J\033[1;1H";
}

// SMALL HELPER FUNCTIONS
// Reusable tools used throughout the program.

// Turns a raw double into a 2-decimal string with thousands separators (1,250.00).
string formatAmount(double amount)
{
    ostringstream oss;
    oss << fixed << setprecision(2) << amount;
    string s = oss.str();

    size_t dot = s.find('.');
    string intPart = (dot == string::npos) ? s : s.substr(0, dot);
    string fracPart = (dot == string::npos) ? "" : s.substr(dot);

    string withCommas;
    int len = (int)intPart.length();
    for (int i = 0; i < len; ++i)
    {
        if (i > 0 && (len - i) % 3 == 0)
            withCommas += ',';
        withCommas += intPart[i];
    }
    return withCommas + fracPart;
}

// Formats an amount as "GHS 1,250.00".
string formatGHS(double amount)
{
    return "GHS " + formatAmount(amount);
}

// Validates a password: minimum 6 characters and at least one number.
bool isValidPassword(const string &pwd)
{
    if (pwd.length() < 6)
        return false;
    for (char c : pwd)
        if (isdigit(static_cast<unsigned char>(c)))
            return true;
    return false;
}

// Reads a line that must contain at least one non-whitespace character.
// Re-prompts (in RED) until a valid non-empty name is entered.
string readNonEmptyString(const string &prompt)
{
    string value;
    while (true)
    {
        cout << YELLOW << prompt << RESET;
        getline(cin, value);
        bool hasContent = false;
        for (char c : value)
            if (!isspace(static_cast<unsigned char>(c)))
                hasContent = true;
        if (hasContent)
            return value;
        cout << RED << "Customer name cannot be empty. Please enter a valid name." << RESET << endl;
    }
}

// Returns the current date and time as "YYYY-MM-DD HH:MM".
string getTimestamp()
{
    time_t now = time(nullptr);
    tm *lt = localtime(&now);
    ostringstream oss;
    oss << (1900 + lt->tm_year) << "-"
        << setw(2) << setfill('0') << (1 + lt->tm_mon) << "-"
        << setw(2) << setfill('0') << lt->tm_mday << " "
        << setw(2) << setfill('0') << lt->tm_hour << ":"
        << setw(2) << setfill('0') << lt->tm_min;
    return oss.str();
}

// Reads a whole number safely; re-prompts on invalid input instead of crashing.
int readInt(const string &prompt)
{
    int value;
    while (true)
    {
        cout << YELLOW << prompt << RESET;
        cin >> value;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << RED << "Please enter a whole number.\n"
                 << RESET;
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

// Same as readInt but for money; also refuses negative amounts.
double readAmount(const string &prompt)
{
    double value;
    while (true)
    {
        cout << YELLOW << prompt << RESET;
        cin >> value;
        if (cin.fail() || value < 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << RED << "Please enter a valid, non-negative amount.\n"
                 << RESET;
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

// Masked password input (shows '*', supports Backspace).
// Platform-specific: Windows uses conio.h, Linux/Mac uses termios.
string getMaskedPassword(const string &prompt)
{
    cout << YELLOW << prompt << RESET;
    string password;

#ifdef _WIN32
    char ch;
    while ((ch = _getch()) != '\r')
    { // Enter key on Windows
        if (ch == '\b')
        { // Backspace
            if (!password.empty())
            {
                password.pop_back();
                cout << "\b \b"; // erase the last '*' on screen
            }
        }
        else
        {
            password.push_back(ch);
            cout << '*';
        }
    }
    cout << endl;
#else
    termios oldSettings;
    if (tcgetattr(STDIN_FILENO, &oldSettings) != 0)
    {
        // Not a real interactive terminal (e.g. input piped from a file
        // during testing) - just fall back to a normal, visible read so the
        // program still works.
        getline(cin, password);
        return password;
    }

    termios rawSettings = oldSettings;
    rawSettings.c_lflag &= ~(ICANON | ECHO); // turn off line-buffering + echo
    tcsetattr(STDIN_FILENO, TCSANOW, &rawSettings);

    char ch;
    while (read(STDIN_FILENO, &ch, 1) == 1 && ch != '\n')
    {
        if (ch == 127 || ch == 8)
        { // Backspace/Delete
            if (!password.empty())
            {
                password.pop_back();
                cout << "\b \b";
            }
        }
        else
        {
            password.push_back(ch);
            cout << '*';
        }
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings); // restore normal terminal mode
    cout << endl;
#endif
    return password;
}

// CUSTOMER CLASS
// Stores customer information.
class Customer
{
private:
    string name;
    int id;

public:
    Customer(string n = "", int i = 0) : name(n), id(i) {}

    string getName() const { return name; }
    int getId() const { return id; }

    void displayCustomer() const
    {
        cout << "Customer Name: " << name << endl;
        cout << "Customer ID  : " << id << endl;
    }
};

// BANKACCOUNT CLASS
// Stores one account: balance, password, and transaction history.
class BankAccount
{
private:
    Customer customer;
    int accountNumber;
    double balance;
    string password;
    vector<string> transactionLog;

    // STATIC MEMBER: shared counter that generates unique account numbers.
    static int nextAccountNumber;

    // Stores a timestamped transaction log entry (format: "type|detail").
    void log(const string &type, const string &detail)
    {
        transactionLog.push_back("[" + getTimestamp() + "] " + type + "|" + detail);
    }

public:
    BankAccount(Customer c, double openingBalance, string pwd)
        : customer(c), accountNumber(nextAccountNumber++),
          balance(openingBalance), password(pwd)
    {
        log("Account Opened", "Opening Balance: " + formatGHS(balance));
    }

    int getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }
    string getCustomerName() const { return customer.getName(); }
    int getCustomerId() const { return customer.getId(); }
    bool verifyPassword(const string &pwd) const { return pwd == password; }

    void deposit(double amount)
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

    void withdraw(double amount)
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

    void changePassword()
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

    void checkBalance()
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

    void displayTransactionLog() const
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

    // Internal transfer helpers (no password re-check; used by Bank::transferFunds).
    void receiveInternal(double amount)
    {
        balance += amount;
        log("Transfer Received", formatGHS(amount));
    }
    void sendInternal(double amount)
    {
        balance -= amount;
        log("Transfer Sent", formatGHS(amount));
    }

    friend void displayAccountDetails(const BankAccount &account);
};

int BankAccount::nextAccountNumber = 1001;

// FRIEND FUNCTION: accesses private members of BankAccount without being a member.
void displayAccountDetails(const BankAccount &account)
{
    cout << BOLD << CYAN << "==========Account Details==========" << RESET << endl;
    account.customer.displayCustomer();
    cout << "Account Number : " << account.accountNumber << endl;
    cout << "Current Balance: " << formatGHS(account.balance) << endl;
    cout << "Transactions   : " << account.transactionLog.size() << endl;
}

// BANK CLASS
// (COMPOSITION) Owns a collection of BankAccount objects and routes every
// menu action to the right account by its account number.
class Bank
{
private:
    vector<BankAccount> accounts;

    // Searches accounts for a matching number; returns nullptr if not found.
    BankAccount *findAccount(int accNum)
    {
        for (auto &acc : accounts)
            if (acc.getAccountNumber() == accNum)
                return &acc;
        return nullptr;
    }

public:
    // Checks whether a Customer ID is already in use.
    bool isCustomerIdTaken(int custId) const
    {
        for (const auto &acc : accounts)
            if (acc.getCustomerId() == custId)
                return true;
        return false;
    }

    // Creates an account; returns its number, or -1 if the Customer ID is taken.
    int createAccount(const string &name, int custId, double openingBalance, const string &pwd)
    {
        if (isCustomerIdTaken(custId))
            return -1;
        Customer c(name, custId);
        accounts.push_back(BankAccount(c, openingBalance, pwd));
        return accounts.back().getAccountNumber();
    }

    void deposit(int accNum, double amount)
    {
        BankAccount *acc = findAccount(accNum);
        if (!acc)
        {
            cout << RED << "Account not found." << RESET << endl;
            return;
        }
        acc->deposit(amount);
    }

    void withdraw(int accNum, double amount)
    {
        BankAccount *acc = findAccount(accNum);
        if (!acc)
        {
            cout << RED << "Account not found." << RESET << endl;
            return;
        }
        acc->withdraw(amount);
    }

    void checkBalance(int accNum)
    {
        BankAccount *acc = findAccount(accNum);
        if (!acc)
        {
            cout << RED << "Account not found." << RESET << endl;
            return;
        }
        acc->checkBalance();
    }

    void changePassword(int accNum)
    {
        BankAccount *acc = findAccount(accNum);
        if (!acc)
        {
            cout << RED << "Account not found." << RESET << endl;
            return;
        }
        acc->changePassword();
    }

    void showTransactionLog(int accNum)
    {
        BankAccount *acc = findAccount(accNum);
        if (!acc)
        {
            cout << RED << "Account not found." << RESET << endl;
            return;
        }
        acc->displayTransactionLog();
    }

    void showAccountDetails(int accNum)
    {
        BankAccount *acc = findAccount(accNum);
        if (!acc)
        {
            cout << RED << "Account not found." << RESET << endl;
            return;
        }
        displayAccountDetails(*acc);
    }

    // Transfers money between two accounts in one menu option.
    void transferFunds(int fromAccNum, int toAccNum, double amount)
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

    // Lists every account in the bank.
    void listAllAccounts() const
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

    // Shows bank-wide totals (total accounts and funds held).
    void bankSummary() const
    {
        double totalFunds = 0.0;
        for (const auto &acc : accounts)
            totalFunds += acc.getBalance();

        cout << BOLD << CYAN << "==========Bank Summary==========" << RESET << endl;
        cout << GREEN << "Total Accounts   : " << accounts.size() << RESET << endl;
        cout << GREEN << "Total Funds Held : " << formatGHS(totalFunds) << RESET << endl;
    }
};

// SECRET CREDITS MENU (easter egg - not listed on the menu).
void showCredits()
{
    struct Member
    {
        string name;
        string idNumber;
    };

    vector<Member> members = {
        {"Michael Agyenim Boateng Anning", "SRI.41.008.26.25"},
        {"Christian David Takyi", "SRI.41.008.108.25"},
        {"Dawuda Kashafatu", "SRI.41.008.053.25"},
        {"Maame Esi Ohenewaa Andoh", "SRI.41.008.025.25"},
        {"Rita Awuviri", "SRI.41.008.039.25"},
        {"Oduro Appiah Kwaku", "SRI.41.008.089.25"}
    };

    cout << "\n"
         << BOLD << CYAN << "==========================================\n"
         << "            YOU FOUND THE SECRET MENU!    \n"
         << "==========================================\n"
         << RESET;
    cout << YELLOW << "Bank Account Management System - Project Team\n\n" << RESET;

    for (const auto &m : members)
    {
        cout << GREEN << "  * " << RESET << m.name
             << "  " << CYAN << "(" << m.idNumber << ")" << RESET << endl;
    }

    cout << "\n"
         << BOLD << CYAN << "==========================================\n"
         << RESET;
    cout << YELLOW << "Press Enter to return to the menu..." << RESET;
    cin.get();
}

// MAIN - MENU DRIVEN INTERFACE
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
            else {
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
