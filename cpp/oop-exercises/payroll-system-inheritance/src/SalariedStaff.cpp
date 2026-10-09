#include "SalariedStaff.h"
#include <iomanip>

SalariedStaff::SalariedStaff(int empNo,
                             string name,
                             string dept,
                             double monthlySal)
    : Employee(empNo, name, dept),
      monthlySalary(monthlySal)
{
}

double SalariedStaff::salary()
{
    return monthlySalary;
}

void SalariedStaff::display()
{
    Employee::display();

    cout << "Category    : Salaried Staff" << endl;
    cout << "Salary      : GHS "
         << fixed << setprecision(2)
         << salary() << endl;
}
