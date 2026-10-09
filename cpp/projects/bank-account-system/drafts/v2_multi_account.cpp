/*
    ============================================================================
    BANK ACCOUNT MANAGEMENT SYSTEM (v2 - Multi-Account Edition)
    ----------------------------------------------------------------------------
    This is a revised version of the group's original single-account program.

    WHAT CHANGED AND WHY (see the full write-up for the long version):
      1. FIXED: the system now manages MANY accounts at once, through a new
         Bank class, instead of hard-coding one Customer/BankAccount in main().
      2. NEW: passwords are typed in as **** instead of plain text.
      3. NEW: every account gets a unique account number automatically.
      4. NEW: transactions are timestamped.
      5. NEW: money can be transferred directly between two accounts.
      6. NEW: menu input is validated so the program never crashes just
         because someone typed a letter instead of a number.
    ============================================================================
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <limits>

// Password masking needs different low-level tools on Windows vs Linux/Mac,
// so we pick the right header at compile time depending on the platform.
#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

using namespace std;

// ============================================================================
// CONSOLE COLOURS
// A small set of ANSI colour codes, used to make the output easier to read
// at a glance: cyan for headers, yellow for prompts, green for success
// messages, red for errors/warnings. Linux and Mac terminals understand
// these codes natively. Windows terminals need colour support switched on
// first - enableConsoleColours() does that, and is called once at the very
// start of main().
// ============================================================================
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
    // Linux/Mac terminals already understand ANSI colour codes natively,
    // so there is nothing extra to switch on here.
}
#endif

// ============================================================================
// SECTION 1: SMALL HELPER FUNCTIONS
// These don't belong to any class - they are just reusable tools used
// throughout the program.
// ============================================================================

// Turns a raw double like 1500.5 into a clean 2-decimal string "1500.50".
string formatAmount(double amount)
{
    ostringstream oss;
    oss << fixed << setprecision(2) << amount;
    return oss.str();
}

// Returns the current date and time as "YYYY-MM-DD HH:MM", so every
// transaction can be stamped with when it actually happened.
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

// Reads a whole number safely. If the user types something that isn't a
// number, cin would normally break in a way that causes an infinite loop -
// this clears that error state and asks again instead of crashing.
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

// Same idea as readInt, but for money amounts, and it also refuses negative
// numbers (you can't deposit or withdraw -50 cedis).
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

// masked password input. Instead of showing the password as the
// user types it, we print '*' for every character and support Backspace to
// correct mistakes. This needs to briefly turn off the terminal's normal
// "echo what I type" behaviour, which is done differently on Windows
// (conio.h) versus Linux/Mac (termios), hence the #ifdef.
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

// ============================================================================
// SECTION 2: CUSTOMER CLASS
// Just holds the two facts we need about the person who owns an account.
// ============================================================================
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

// ============================================================================
// SECTION 3: BANKACCOUNT CLASS
// Everything to do with ONE account: its own balance, its own password, its
// own transaction history. The Bank class below is what lets us have many
// of these at once.
// ============================================================================
class BankAccount
{
private:
    Customer customer;
    int accountNumber;
    double balance;
    string password;
    vector<string> transactionLog;

    // a static member is shared by every BankAccount object
    //  instead of belonging to just one. We use it as a counter so every
    //  new account automatically gets its own account number - no two
    //  accounts can ever collide, and nobody has to invent a number by hand.
    static int nextAccountNumber;

    // Small private helper so every log entry is timestamped the same way.
    void log(const string &entry)
    {
        transactionLog.push_back("[" + getTimestamp() + "] " + entry);
    }

public:
    BankAccount(Customer c, double openingBalance, string pwd)
        : customer(c), accountNumber(nextAccountNumber++),
          balance(openingBalance), password(pwd)
    {
        log("Account opened with balance: GHS " + formatAmount(balance));
    }

    int getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }
    string getCustomerName() const { return customer.getName(); }
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
        log("Deposited GHS " + formatAmount(amount) + ", New Balance: GHS " + formatAmount(balance));
        cout << GREEN << "Deposited: GHS " << formatAmount(amount) << RESET << endl;
        cout << GREEN << "New Balance: GHS " << formatAmount(balance) << RESET << endl;
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
        log("Withdrew GHS " + formatAmount(amount) + ", New Balance: GHS " + formatAmount(balance));
        cout << GREEN << "Withdrew: GHS " << formatAmount(amount) << RESET << endl;
        cout << GREEN << "New Balance: GHS " << formatAmount(balance) << RESET << endl;
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
        log("Password changed.");
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
        cout << GREEN << "Current Balance (GHS): " << formatAmount(balance) << RESET << endl;
    }

    void displayTransactionLog() const
    {
        cout << BOLD << CYAN << "==========Transaction Log (Account #" << accountNumber << ")==========" << RESET << endl;
        if (transactionLog.empty())
        {
            cout << YELLOW << "No transactions yet." << RESET << endl;
        }
        else
        {
            for (size_t i = 0; i < transactionLog.size(); ++i)
                cout << i + 1 << ". " << transactionLog[i] << endl;
        }
    }

    //(supports transfers): these two move money WITHOUT
    // re-checking the password. They are only ever called by
    // Bank::transferFunds, after that function has already verified the
    // sender's password once - so the customer isn't asked to type their
    // password twice for a single transfer.
    void receiveInternal(double amount)
    {
        balance += amount;
        log("Received transfer: GHS " + formatAmount(amount) + ", New Balance: GHS " + formatAmount(balance));
    }
    void sendInternal(double amount)
    {
        balance -= amount;
        log("Sent transfer: GHS " + formatAmount(amount) + ", New Balance: GHS " + formatAmount(balance));
    }

    friend void displayAccountDetails(const BankAccount &account);
};

int BankAccount::nextAccountNumber = 1001;

// Kept as a friend function (not a class member), and it's a nice small example of how a
// friend function can still reach an object's private data when it needs to.
void displayAccountDetails(const BankAccount &account)
{
    cout << BOLD << CYAN << "==========Account Details==========" << RESET << endl;
    account.customer.displayCustomer();
    cout << "Account Number : " << account.accountNumber << endl;
    cout << "Current Balance: GHS " << formatAmount(account.balance) << endl;
    cout << "Transactions   : " << account.transactionLog.size() << endl;
}

// ============================================================================
// SECTION 4: BANK CLASS
// this class owns a whole collection of accounts (a vector), so the
// program is no longer limited to the one account it started with. Every
// menu action in main() goes through this class, which looks up the right
// account by its account number first.
// ============================================================================
class Bank
{
private:
    vector<BankAccount> accounts;

    // Looks through every account for one matching this number.
    // Returns a pointer so the caller can actually change the real
    // account (not a copy of it); returns nullptr if nothing matches.
    BankAccount *findAccount(int accNum)
    {
        for (auto &acc : accounts)
            if (acc.getAccountNumber() == accNum)
                return &acc;
        return nullptr;
    }

public:
    int createAccount(const string &name, int custId, double openingBalance, const string &pwd)
    {
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

    //  move money straight from one account to another in a
    // single menu option, instead of the user having to withdraw from
    // one and manually deposit into the other themselves.
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

        // Balance is checked BEFORE any money moves, so there's no way
        // for the transfer to take money out of one account without it
        // safely arriving in the other.
        from->sendInternal(amount);
        to->receiveInternal(amount);
        cout << GREEN << "Transferred GHS " << formatAmount(amount) << " from Account #" << fromAccNum
             << " to Account #" << toAccNum << "." << RESET << endl;
    }

    //  a quick directory of every account in the bank - useful
    // once there's more than one, so a user can see what account numbers
    // exist without needing to remember them all.
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
                 << "  |  Balance: GHS " << formatAmount(acc.getBalance()) << endl;
        }
    }

    //  a bank-wide summary, the kind of totals a manager
    // would want - shows off that the Bank class can reason about ALL
    // accounts together, not just one at a time.
    void bankSummary() const
    {
        double totalFunds = 0.0;
        for (const auto &acc : accounts)
            totalFunds += acc.getBalance();

        cout << BOLD << CYAN << "==========Bank Summary==========" << RESET << endl;
        cout << GREEN << "Total Accounts   : " << accounts.size() << RESET << endl;
        cout << GREEN << "Total Funds Held : GHS " << formatAmount(totalFunds) << RESET << endl;
    }
};

// ============================================================================
// SECTION 5: MAIN - MENU DRIVEN INTERFACE
// main() only asks "what does the user want?" and hands the real work to the
// Bank object - all the banking logic lives in the classes above, not here.
// ============================================================================
int main()
{
    enableConsoleColours(); // switches on ANSI colour support on Windows; no-op elsewhere

    Bank bank;
    int choice;

    do
    {
        cout << "\n"
             << BOLD << CYAN << "==========Bank Account Menu==========" << RESET << endl;
        cout << CYAN << "1. Create New Account" << RESET << endl;
        cout << CYAN << "2. Deposit" << RESET << endl;
        cout << CYAN << "3. Withdraw" << RESET << endl;
        cout << CYAN << "4. Check Balance" << RESET << endl;
        cout << CYAN << "5. Change Password" << RESET << endl;
        cout << CYAN << "6. Transfer Funds" << RESET << endl;
        cout << CYAN << "7. Display Transaction Log" << RESET << endl;
        cout << CYAN << "8. Display Account Details" << RESET << endl;
        cout << CYAN << "9. List All Accounts" << RESET << endl;
        cout << CYAN << "10. Bank Summary" << RESET << endl;
        cout << CYAN << "11. Exit" << RESET << endl;

        choice = readInt("Enter your choice: ");

        if (choice == 1)
        {
            cout << BOLD << CYAN << "==========Create New Account==========" << RESET << endl;
            string name;
            cout << YELLOW << "Enter Customer Name: " << RESET;
            getline(cin, name);
            int id = readInt("Enter Customer ID: ");
            double opening = readAmount("Enter Opening Balance: ");
            string pwd = getMaskedPassword("Set Account Password: ");

            int accNum = bank.createAccount(name, id, opening, pwd);
            cout << GREEN << "\nAccount created successfully!" << RESET << endl;
            cout << GREEN << "Your Account Number is: " << accNum << RESET << endl;
            cout << YELLOW << "Please remember this number - it is needed for every transaction." << RESET << endl;
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
            cout << CYAN << "Exiting..." << RESET << endl;
            break;
        }
        else
        {
            cout << RED << "Invalid choice. Please try again." << RESET << endl;
        }

    } while (choice != 11);

    return 0;
}
