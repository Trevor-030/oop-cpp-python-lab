/*
 * Simple Payroll Application
 * ---------------------------
 * Individual Assignment
 *
 * Employee is an abstract base class with two pure virtual functions:
 *      salary()   -> calculates and returns the pay for that employee
 *      display()  -> shows employee no, name, and salary
 *
 * Three concrete classes derive from Employee:
 *      SalariedEmployee    - paid a fixed amount per month
 *      HourlyEmployee      - paid per hour worked
 *      CommissionedEmployee- paid a base amount + bonus for each target completed
 *
 * An array of Employee* is used to store objects of all three types and
 * salary()/display() are called polymorphically (through the base class
 * pointer, using virtual dispatch) to generate the final payroll report.
 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// ---------------------------------------------------------------------
// Abstract base class
// ---------------------------------------------------------------------
class Employee {
protected:
    int empNo;
    string name;

public:
    Employee(int empNo, const string& name) : empNo(empNo), name(name) {}

    virtual ~Employee() {}

    // Pure virtual functions -> make this class abstract
    virtual double salary() = 0;
    virtual void display() = 0;

    int getEmpNo() const { return empNo; }
    string getName() const { return name; }
};

// ---------------------------------------------------------------------
// Salaried Employee - paid a fixed monthly salary
// ---------------------------------------------------------------------
class SalariedEmployee : public Employee {
private:
    double monthlySalary;

public:
    SalariedEmployee(int empNo, const string& name, double monthlySalary)
        : Employee(empNo, name), monthlySalary(monthlySalary) {}

    double salary() override {
        return monthlySalary;
    }

    void display() override {
        cout << left << setw(8) << empNo
             << setw(20) << name
             << setw(15) << "Salaried"
             << fixed << setprecision(2) << salary() << endl;
    }
};

// ---------------------------------------------------------------------
// Hourly Employee - paid per hour worked
// ---------------------------------------------------------------------
class HourlyEmployee : public Employee {
private:
    double hoursWorked;
    double hourlyRate;

public:
    HourlyEmployee(int empNo, const string& name, double hoursWorked, double hourlyRate)
        : Employee(empNo, name), hoursWorked(hoursWorked), hourlyRate(hourlyRate) {}

    double salary() override {
        // Simple overtime rule: hours beyond 40 paid at 1.5x rate
        if (hoursWorked > 40) {
            double overtimeHours = hoursWorked - 40;
            return (40 * hourlyRate) + (overtimeHours * hourlyRate * 1.5);
        }
        return hoursWorked * hourlyRate;
    }

    void display() override {
        cout << left << setw(8) << empNo
             << setw(20) << name
             << setw(15) << "Hourly"
             << fixed << setprecision(2) << salary() << endl;
    }
};

// ---------------------------------------------------------------------
// Commissioned Employee - base pay + bonus per target completed
// ---------------------------------------------------------------------
class CommissionedEmployee : public Employee {
private:
    double baseSalary;
    double bonusPerTarget;
    int targetsCompleted;

public:
    CommissionedEmployee(int empNo, const string& name, double baseSalary,
                          double bonusPerTarget, int targetsCompleted)
        : Employee(empNo, name), baseSalary(baseSalary),
          bonusPerTarget(bonusPerTarget), targetsCompleted(targetsCompleted) {}

    double salary() override {
        return baseSalary + (bonusPerTarget * targetsCompleted);
    }

    void display() override {
        cout << left << setw(8) << empNo
             << setw(20) << name
             << setw(15) << "Commissioned"
             << fixed << setprecision(2) << salary() << endl;
    }
};

// ---------------------------------------------------------------------
// Main - builds an array of Employee objects and generates a report
// ---------------------------------------------------------------------


