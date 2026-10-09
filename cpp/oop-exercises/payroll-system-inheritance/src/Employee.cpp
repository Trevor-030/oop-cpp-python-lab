#include "Employee.h"

Employee::Employee(int empNo, string name, string dept)
    : employeeNo(empNo), employeeName(name), department(dept)
{
}

void Employee::display()
{
    cout << "Employee No : " << employeeNo << endl;
    cout << "Name        : " << employeeName << endl;
    cout << "Department  : " << department << endl;
}
