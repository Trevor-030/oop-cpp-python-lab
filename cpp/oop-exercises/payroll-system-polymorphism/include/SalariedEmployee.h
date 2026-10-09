#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include "Employee.h"

// Salaried Employee - paid a fixed monthly salary
class SalariedEmployee : public Employee {
private:
    double monthlySalary;

public:
    SalariedEmployee(int empNo, const std::string& name, double monthlySalary);

    double salary() override;
    void display() override;
};

#endif // SALARIEDEMPLOYEE_H
