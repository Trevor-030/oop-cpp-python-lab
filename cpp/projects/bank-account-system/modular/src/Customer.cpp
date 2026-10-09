#include "Customer.h"
#include <iostream>

using namespace std;

Customer::Customer(string n, int i) : name(n), id(i) {}

string Customer::getName() const { return name; }
int Customer::getId() const { return id; }

void Customer::displayCustomer() const
{
    cout << "Customer Name: " << name << endl;
    cout << "Customer ID  : " << id << endl;
}
