#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

#include "Employee.h"

// Hourly Employee - paid per hour worked
class HourlyEmployee : public Employee {
private:
    double hoursWorked;
    double hourlyRate;

public:
    HourlyEmployee(int empNo, const std::string& name, double hoursWorked, double hourlyRate);

    double salary() override;
    void display() override;
};

#endif // HOURLYEMPLOYEE_H
