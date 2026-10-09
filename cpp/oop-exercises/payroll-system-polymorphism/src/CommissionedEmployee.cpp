#include "CommissionedEmployee.h"
#include <iostream>
#include <iomanip>
using namespace std;

CommissionedEmployee::CommissionedEmployee(int empNo, const string& name, double baseSalary,
                                            double bonusPerTarget, int targetsCompleted)
    : Employee(empNo, name), baseSalary(baseSalary),
      bonusPerTarget(bonusPerTarget), targetsCompleted(targetsCompleted) {}

double CommissionedEmployee::salary() {
    return baseSalary + (bonusPerTarget * targetsCompleted);
}

void CommissionedEmployee::display() {
    cout << left << setw(8) << empNo
         << setw(20) << name
         << setw(15) << "Commissioned"
         << fixed << setprecision(2) << salary() << endl;
}
