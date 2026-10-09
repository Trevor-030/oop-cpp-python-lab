#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
    private:
        std::string name;
        int id;

    public:
        Customer(std::string n, int i);
        ~Customer();

        void displayCustomer();
};

#endif // CUSTOMER_H
