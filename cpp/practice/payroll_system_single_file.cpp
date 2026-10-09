/*
  =====================================================================
   University of Mines and Technology, Essikado Campus
   Staff Payroll System
  ---------------------------------------------------------------------
   Demonstrates single-level inheritance with THREE independent
   derived classes: SalariedStaff, HourlyStaff, CommissionedStaff.
 
   No base-class pointers or virtual functions are used. Each staff
   category is stored in, and processed through, its own array, and
   each object's OWN salary() / display() functions are called
   directly (no runtime polymorphism).
  =====================================================================
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// =====================================================================
// 1. BASE CLASS: Employee
// =====================================================================
class Employee {
protected:
    int employeeNo;
    string employeeName;
    string department;

public:
    Employee(int empNo, string name, string dept)
        : employeeNo(empNo), employeeName(name), department(dept) {}

    void display() {
        cout << "Employee No : " << employeeNo   << endl;
        cout << "Name        : " << employeeName << endl;
        cout << "Department  : " << department   << endl;
    }
};

// =====================================================================
// 2. DERIVED CLASS: SalariedStaff (registrars, deans, admin officers)
// =====================================================================
class SalariedStaff : public Employee {
private:
    double monthlySalary;

public:
    SalariedStaff(int empNo, string name, string dept, double monthlySal)
        : Employee(empNo, name, dept), monthlySalary(monthlySal) {}

    double salary() {
        return monthlySalary;
    }

    void display() {
        Employee::display();
        cout << "Category    : Salaried Staff" << endl;
        cout << "Salary      : GHS " << fixed << setprecision(2) << salary() << endl;
    }
};

// =====================================================================
// 3. DERIVED CLASS: HourlyStaff (part-time / adjunct lecturers)
// =====================================================================
class HourlyStaff : public Employee {
private:
    double hoursWorked;
    double ratePerHour;

public:
    HourlyStaff(int empNo, string name, string dept, double hours, double rate)
        : Employee(empNo, name, dept), hoursWorked(hours), ratePerHour(rate) {}

    double salary() {
        return hoursWorked * ratePerHour;
    }

    void display() {
        Employee::display();
        cout << "Category    : Hourly Staff" << endl;
        cout << "Hours Worked: " << hoursWorked << endl;
        cout << "Rate/Hour   : GHS " << fixed << setprecision(2) << ratePerHour << endl;
        cout << "Salary      : GHS " << fixed << setprecision(2) << salary() << endl;
    }
};

// =====================================================================
// 4. DERIVED CLASS: CommissionedStaff (admissions / recruitment officers)
// =====================================================================
class CommissionedStaff : public Employee {
private:
    double baseSalary;
    int targetsCompleted;
    double bonusPerTarget;

public:
    CommissionedStaff(int empNo, string name, string dept, double base, int targets, double bonus)
        : Employee(empNo, name, dept), baseSalary(base), targetsCompleted(targets), bonusPerTarget(bonus) {}

    double salary() {
        return baseSalary + (targetsCompleted * bonusPerTarget);
    }

    void display() {
        Employee::display();
        cout << "Category    : Commissioned Staff" << endl;
        cout << "Base Salary : GHS " << fixed << setprecision(2) << baseSalary << endl;
        cout << "Targets Met : " << targetsCompleted << endl;
        cout << "Bonus/Target: GHS " << fixed << setprecision(2) << bonusPerTarget << endl;
        cout << "Salary      : GHS " << fixed << setprecision(2) << salary() << endl;
    }
};

// =====================================================================
// 5. MAIN PROGRAM
// =====================================================================
int main() {
    // ---- Separate arrays for each staff category (no base pointers) ----
    SalariedStaff salariedArr[] = {
        SalariedStaff(1001, "Ama Owusu-Sekyere", "Registrar's Office",   6500.00),
        SalariedStaff(1002, "Kwabena Asante",     "Finance Directorate", 7200.00),
        SalariedStaff(1003, "Efua Darkoa Mensah", "Academic Affairs",    6800.00)
    };
    int salariedCount = sizeof(salariedArr) / sizeof(salariedArr[0]);

    HourlyStaff hourlyArr[] = {
        HourlyStaff(2001, "Dr. Kojo Boateng",    "Mining Engineering",           18, 120.00),
        HourlyStaff(2002, "Ing. Adwoa Frimpong",  "Electrical & Electronic Eng.", 22, 110.00),
        HourlyStaff(2003, "Mr. Yaw Antwi",        "Geological Engineering",       15, 95.00)
    };
    int hourlyCount = sizeof(hourlyArr) / sizeof(hourlyArr[0]);
 
    CommissionedStaff commissionedArr[] = {
        CommissionedStaff(3001, "Abena Nyarko", "Admissions & Recruitment", 2500.00, 9,  150.00),
        CommissionedStaff(3002, "Kwesi Appiah", "Admissions & Recruitment", 2500.00, 6,  150.00),
        CommissionedStaff(3003, "Linda Ofosu",  "Admissions & Recruitment", 2800.00, 12, 150.00)
    };
    int commissionedCount = sizeof(commissionedArr) / sizeof(commissionedArr[0]);

    double totalSalaried = 0.0, totalHourly = 0.0, totalCommissioned = 0.0;

    cout << "=====================================================================\n";
    cout << "        UNIVERSITY OF MINES AND TECHNOLOGY - ESSIKADO CAMPUS\n";
    cout << "                       STAFF PAYROLL REPORT\n";
    cout << "=====================================================================\n\n";

    // ---- SALARIED STAFF ----
    cout << "---------------------------- SALARIED STAFF ------------------------\n";
    for (int i = 0; i < salariedCount; i++) {
        salariedArr[i].display();                 // own display()
        totalSalaried += salariedArr[i].salary();  // own salary(), called directly
        cout << "---------------------------------------------------------------------\n";
    }
    cout << "Subtotal - Salaried Staff: GHS " << fixed << setprecision(2) << totalSalaried << "\n\n";

    // ---- HOURLY STAFF ----
    cout << "----------------------------- HOURLY STAFF ---------------------------\n";
    for (int i = 0; i < hourlyCount; i++) {
        hourlyArr[i].display();
        totalHourly += hourlyArr[i].salary();
        cout << "---------------------------------------------------------------------\n";
    }
    cout << "Subtotal - Hourly Staff: GHS " << fixed << setprecision(2) << totalHourly << "\n\n";

    // ---- COMMISSIONED STAFF ----
    cout << "-------------------------- COMMISSIONED STAFF ------------------------\n";
    for (int i = 0; i < commissionedCount; i++) {
        commissionedArr[i].display();
        totalCommissioned += commissionedArr[i].salary();
        cout << "---------------------------------------------------------------------\n";
    }
    cout << "Subtotal - Commissioned Staff: GHS " << fixed << setprecision(2) << totalCommissioned << "\n\n";

    // ---- GRAND TOTAL ----
    double grandTotal = totalSalaried + totalHourly + totalCommissioned;
    cout << "=====================================================================\n";
    cout << "TOTAL MONTHLY PAYROLL (ALL STAFF): GHS " << fixed << setprecision(2) << grandTotal << "\n";
    cout << "=====================================================================\n";

    return 0;
}
