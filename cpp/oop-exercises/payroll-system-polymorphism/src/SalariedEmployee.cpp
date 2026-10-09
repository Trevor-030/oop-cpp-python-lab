#include "SalariedEmployee.h"
#include <iostream>
#include <iomanip>
using namespace std;

SalariedEmployee::SalariedEmployee(int empNo, const string& name, double monthlySalary)
    : Employee(empNo, name), monthlySalary(monthlySalary) {}

double SalariedEmployee::salary() {
    return monthlySalary;
}

void SalariedEmployee::display() {
    cout << left << setw(8) << empNo
         << setw(20) << name
         << setw(15) << "Salaried"
         << fixed << setprecision(2) << salary() << endl;
}
