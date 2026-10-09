#ifndef COMMISSIONEDSTAFF_H
#define COMMISSIONEDSTAFF_H

#include "Employee.h"

class CommissionedStaff : public Employee {
private:
    double baseSalary;
    int targetsCompleted;
    double bonusPerTarget;

public:
    CommissionedStaff(int empNo,
                      string name,
                      string dept,
                      double base,
                      int targets,
                      double bonus);

    double salary();
    void display();
};

#endif
