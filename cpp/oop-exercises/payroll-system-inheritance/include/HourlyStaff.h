#ifndef HOURLYSTAFF_H
#define HOURLYSTAFF_H

#include "Employee.h"

class HourlyStaff : public Employee {
private:
    double hoursWorked;
    double ratePerHour;

public:
    HourlyStaff(int empNo, string name,
                string dept,
                double hours,
                double rate);

    double salary();
    void display();
};

#endif
