#include "CommissionedStaff.h"
#include <iomanip>

CommissionedStaff::CommissionedStaff(
    int empNo,
    string name,
    string dept,
    double base,
    int targets,
    double bonus)

    : Employee(empNo, name, dept),
      baseSalary(base),
      targetsCompleted(targets),
      bonusPerTarget(bonus)
{
}

double CommissionedStaff::salary()
{
    return baseSalary +
           (targetsCompleted * bonusPerTarget);
}

void CommissionedStaff::display()
{
    Employee::display();

    cout << "Category    : Commissioned Staff" << endl;
    cout << "Base Salary : GHS "
         << fixed << setprecision(2)
         << baseSalary << endl;

    cout << "Targets Met : "
         << targetsCompleted << endl;

    cout << "Bonus/Target: GHS "
         << bonusPerTarget << endl;

    cout << "Salary      : GHS "
         << salary() << endl;
}
