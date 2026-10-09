#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

// Stores customer information.
class Customer
{
private:
    std::string name;
    int id;

public:
    Customer(std::string n = "", int i = 0);

    std::string getName() const;
    int getId() const;

    void displayCustomer() const;
};

#endif // CUSTOMER_H
