#include "HourlyEmployee.h"
#include <iostream>
#include <iomanip>
using namespace std;

HourlyEmployee::HourlyEmployee(int empNo, const string& name, double hoursWorked, double hourlyRate)
    : Employee(empNo, name), hoursWorked(hoursWorked), hourlyRate(hourlyRate) {}

double HourlyEmployee::salary() {
    // Simple overtime rule: hours beyond 40 paid at 1.5x rate
    if (hoursWorked > 40) {
        double overtimeHours = hoursWorked - 40;
        return (40 * hourlyRate) + (overtimeHours * hourlyRate * 1.5);
    }
    return hoursWorked * hourlyRate;
}

void HourlyEmployee::display() {
    cout << left << setw(8) << empNo
         << setw(20) << name
         << setw(15) << "Hourly"
         << fixed << setprecision(2) << salary() << endl;
}
