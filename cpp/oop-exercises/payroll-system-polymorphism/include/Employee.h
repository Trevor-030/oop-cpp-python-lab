#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

// ---------------------------------------------------------------------
// Abstract base class
// ---------------------------------------------------------------------
class Employee {
protected:
    int empNo;
    std::string name;

public:
    Employee(int empNo, const std::string& name);
    virtual ~Employee();

    // Pure virtual functions -> make this class abstract
    virtual double salary() = 0;
    virtual void display() = 0;

    int getEmpNo() const;
    std::string getName() const;
};

#endif // EMPLOYEE_H
