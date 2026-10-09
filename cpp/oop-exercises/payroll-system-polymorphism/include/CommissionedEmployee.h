#ifndef COMMISSIONEDEMPLOYEE_H
#define COMMISSIONEDEMPLOYEE_H

#include "Employee.h"

// Commissioned Employee - base pay + bonus per target completed
class CommissionedEmployee : public Employee {
private:
    double baseSalary;
    double bonusPerTarget;
    int targetsCompleted;

public:
    CommissionedEmployee(int empNo, const std::string& name, double baseSalary,
                          double bonusPerTarget, int targetsCompleted);

    double salary() override;
    void display() override;
};

#endif // COMMISSIONEDEMPLOYEE_H
