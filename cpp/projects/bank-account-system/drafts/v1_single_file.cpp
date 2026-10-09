#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <sstream>
// member initialization list
/*
: customer(c)

This is called the member initializer list.

Instead of assigning customer inside the constructor body, it initializes it directly.

It is equivalent to saying:
*/
using namespace std;

string formatAmount(double amount) {
    ostringstream oss;
    oss << fixed << setprecision(2) << amount;
    return oss.str();
}

class Customer {
    private:
        string name;
        int id;
        

    public:
        Customer(string n, int i) {
            name = n;
            id = i;
            cout << "\nCustomer Created\n";
        }


        ~Customer() {
            // Destructor
        }

        void displayCustomer(){
            cout << "Customer Name: "<< name << endl;
            cout << "Customer ID: " << id << endl;
        }


};


class BankAccount {
    private:
        Customer customer;
        int accountNumber;
        double balance;
        string password;
        string inputPassword;
        vector<string> transactionLog;

    public:
        BankAccount(Customer c, int acc, double bal, string pwd) : customer(c)
            {
                accountNumber = acc;
                balance = bal;
                password = pwd;
                cout << "\nBank Account Created\n";
            }

        
        ~BankAccount() {
            // Destructor
        }

        void deposit(double amount) {
            cout <<"==========Deposit Transaction=========="<< endl;
            cout <<"Enter Password: " << endl;
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

        void withdraw(double amount) {
            cout <<"==========Withdraw Transaction=========="<< endl;
            cout <<"Enter Password: " << endl;
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

        void changePassword(string newPassword) {
            cout <<"==========Change Password=========="<< endl;
            cout <<"Enter Current Password: " << endl;
            cin >> inputPassword;
            if (inputPassword != password) {
                cout << "Incorrect Password. Password change failed." << endl;
            }
            else {
                password = newPassword;
                cout << "Password changed successfully." << endl;
            }
        }

        void checkBalance() {
            cout <<"==========Balance Check=========="<< endl;
            cout <<"Enter Password: " << endl;
            cin >> inputPassword;
            if (inputPassword != password) {
                cout << "Incorrect Password. Balance check failed." << endl;
            }
            else {
                cout << "Current Balance(GHS): " << formatAmount(balance) << " only" << endl;
            }
            
        }

        friend void displayAccountDetails(BankAccount &account);

        void displayTransactionLog() {
            cout <<"==========Transaction Log=========="<< endl;
            if (transactionLog.empty()) {
                cout << "No transactions yet." << endl;
            }

            else {
                
                for (size_t i = 0; i < transactionLog.size(); ++i) {
                    cout << i + 1 << ". " << transactionLog[i] << endl;
                }
            }
        }
        
};

void displayAccountDetails(BankAccount &account) {
    cout <<"==========Account Details=========="<< endl;
    account.customer.displayCustomer();
    cout << "Account Number: " << account.accountNumber << endl;
    cout << "Total Transactions: " << account.transactionLog.size() << endl;
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

// Hidden password
// Colored Output
// ETC. 