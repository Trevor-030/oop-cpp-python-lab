#include "Employee.h"

Employee::Employee(int empNo, const std::string& name)
    : empNo(empNo), name(name) {}

Employee::~Employee() {}

int Employee::getEmpNo() const {
    return empNo;
}

std::string Employee::getName() const {
    return name;
}
