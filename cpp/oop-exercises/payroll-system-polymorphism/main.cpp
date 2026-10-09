/*
 * Simple Payroll Application
 * ---------------------------
 * Individual Assignment
 *
 * Builds an array of Employee objects (Salaried, Hourly, Commissioned)
 * and calls salary()/display() polymorphically through Employee* to
 * generate the payroll report.
 */

#include <iostream>
#include <iomanip>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "HourlyEmployee.h"
#include "CommissionedEmployee.h"
using namespace std;

int main() {
    const int SIZE = 5;
    Employee* staff[SIZE];

    // Populate the array with different employee types
    staff[0] = new SalariedEmployee(101, "Ama Boateng", 3500.00);
    staff[1] = new HourlyEmployee(102, "Kojo Mensah", 48, 25.00);
    staff[2] = new CommissionedEmployee(103, "Efua Asante", 1000.00, 150.00, 4);
    staff[3] = new SalariedEmployee(104, "Yaw Owusu", 4200.00);
    staff[4] = new HourlyEmployee(105, "Adjoa Sarpong", 36, 20.00);

    cout << "=======================================================\n";
    cout << "                 PAYROLL REPORT\n";
    cout << "=======================================================\n";
    cout << left << setw(8) << "EmpNo" << setw(20) << "Name"
         << setw(15) << "Type" << "Salary (GHS)" << endl;
    cout << "-------------------------------------------------------\n";

    double totalPayroll = 0.0;

    // Polymorphic calls: the actual overridden version (Salaried/Hourly/
    // Commissioned) runs even though we only hold Employee* pointers.
    for (int i = 0; i < SIZE; i++) {
        staff[i]->display();
        totalPayroll += staff[i]->salary();
    }

    cout << "-------------------------------------------------------\n";
    cout << "Total number of employees : " << SIZE << endl;
    cout << fixed << setprecision(2);
    cout << "Total payroll for period   : GHS " << totalPayroll << endl;
    cout << "Average salary             : GHS " << (totalPayroll / SIZE) << endl;
    cout << "=======================================================\n";

    // Clean up dynamically allocated memory
    for (int i = 0; i < SIZE; i++) {
        delete staff[i];
    }

    return 0;
}
/*
int main() {
    const int SIZE = 5;
    Employee* staff[SIZE];

    // Populate the array with different employee types
    staff[0] = new SalariedEmployee(101, "Ama Boateng", 3500.00);
    staff[1] = new HourlyEmployee(102, "Kojo Mensah", 48, 25.00);
    staff[2] = new CommissionedEmployee(103, "Efua Asante", 1000.00, 150.00, 4);
    staff[3] = new SalariedEmployee(104, "Yaw Owusu", 4200.00);
    staff[4] = new HourlyEmployee(105, "Adjoa Sarpong", 36, 20.00);

    cout << "=======================================================\n";
    cout << "                 PAYROLL REPORT\n";
    cout << "=======================================================\n";
    cout << left << setw(8) << "EmpNo" << setw(20) << "Name"
         << setw(15) << "Type" << "Salary (GHS)" << endl;
    cout << "-------------------------------------------------------\n";

    double totalPayroll = 0.0;

    // Polymorphic calls: the actual overridden version (Salaried/Hourly/
    // Commissioned) runs even though we only hold Employee* pointers.
    for (int i = 0; i < SIZE; i++) {
        staff[i]->display();
        totalPayroll += staff[i]->salary();
    }

    cout << "-------------------------------------------------------\n";
    cout << "Total number of employees : " << SIZE << endl;
    cout << fixed << setprecision(2);
    cout << "Total payroll for period   : GHS " << totalPayroll << endl;
    cout << "Average salary             : GHS " << (totalPayroll / SIZE) << endl;
    cout << "=======================================================\n";

    // Clean up dynamically allocated memory
    for (int i = 0; i < SIZE; i++) {
        delete staff[i];
    }

    return 0;
}
*/
