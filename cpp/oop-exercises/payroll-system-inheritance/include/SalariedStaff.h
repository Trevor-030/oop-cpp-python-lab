#ifndef SALARIEDSTAFF_H
#define SALARIEDSTAFF_H

#include "Employee.h"

class SalariedStaff : public Employee {
private:
    double monthlySalary;

public:
    SalariedStaff(int empNo, string name,
                  string dept, double monthlySal);

    double salary();
    void display();
};

#endif
