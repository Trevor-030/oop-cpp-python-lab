#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

using namespace std;

class Employee {
protected:
    int employeeNo;
    string employeeName;
    string department;

public:
    Employee(int empNo, string name, string dept);
    void display();
};

#endif
