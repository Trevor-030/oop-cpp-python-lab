#include "Customer.h"
#include <iostream>
using namespace std;

Customer::Customer(string n, int i) {
    name = n;
    id = i;
    cout << "\nCustomer Created\n";
}

Customer::~Customer() {
    cout << "\nCustomer " << name << " Destroyed\n";
}

void Customer::displayCustomer() {
    cout << "Customer Name: " << name << endl;
    cout << "Customer ID: " << id << endl;
}
