#include "HourlyStaff.h"
#include <iomanip>

HourlyStaff::HourlyStaff(int empNo,
                         string name,
                         string dept,
                         double hours,
                         double rate)
    : Employee(empNo, name, dept),
      hoursWorked(hours),
      ratePerHour(rate)
{
}

double HourlyStaff::salary()
{
    return hoursWorked * ratePerHour;
}

void HourlyStaff::display()
{
    Employee::display();

    cout << "Category    : Hourly Staff" << endl;
    cout << "Hours Worked: " << hoursWorked << endl;
    cout << "Rate/Hour   : GHS "
         << fixed << setprecision(2)
         << ratePerHour << endl;

    cout << "Salary      : GHS "
         << salary() << endl;
}
