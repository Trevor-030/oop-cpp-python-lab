# Payroll System — Inheritance (C++)

OOP exercise demonstrating single inheritance with an `Employee` base class and three derived classes.

## Structure
```
payroll-system-inheritance/
├── include/
│   ├── Employee.h
│   ├── SalariedStaff.h
│   ├── HourlyStaff.h
│   └── CommissionedStaff.h
├── src/
│   ├── Employee.cpp
│   ├── SalariedStaff.cpp
│   ├── HourlyStaff.cpp
│   └── CommissionedStaff.cpp
├── main.cpp
└── Payroll System.cbp (Code::Blocks project)
```

## Class Hierarchy
- **Employee** (base)
  - Protected: `employeeNo`, `employeeName`, `department`
  - `display()` — prints basic info
- **SalariedStaff** : public Employee
  - Private: `monthlySalary`
  - `salary()` — returns monthly salary
- **HourlyStaff** : public Employee
  - Private: `hoursWorked`, `ratePerHour`
  - `salary()` — returns `hoursWorked * ratePerHour`
- **CommissionedStaff** : public Employee
  - Private: `baseSalary`, `itemsSold`, `commissionPerItem`
  - `salary()` — returns `baseSalary + itemsSold * commissionPerItem`

## Build & Run
```bash
g++ -Iinclude main.cpp src/*.cpp -o payroll_inheritance
./payroll_inheritance
```

Or open `Payroll System.cbp` in Code::Blocks.

## Example Output
```
=====================================================================
        UNIVERSITY OF MINES AND TECHNOLOGY - ESSIKADO CAMPUS
                       STAFF PAYROLL REPORT
=====================================================================

---------------------------- SALARIED STAFF ------------------------
Employee No: 1001
Name: Ama Owusu-Sekyere
Department: Registrar's Office
Monthly Salary: GHS 6500.00
---------------------------------------------------------------------
Subtotal - Salaried Staff: GHS 20500.00

----------------------------- HOURLY STAFF ---------------------------
Employee No: 2001
Name: Dr. Kojo Boateng
Department: Mining Engineering
Hours Worked: 18
Rate per Hour: GHS 120.00
Salary: GHS 2160.00
---------------------------------------------------------------------
Subtotal - Hourly Staff: GHS 6370.00

-------------------------- COMMISSIONED STAFF ------------------------
Employee No: 3001
Name: Abena Nyarko
Department: Admissions & Recruitment
Base Salary: GHS 2500.00
Items Sold: 9
Commission per Item: GHS 150.00
Salary: GHS 3850.00
---------------------------------------------------------------------
Subtotal - Commissioned Staff: GHS 12050.00

=====================================================================
TOTAL MONTHLY PAYROLL (ALL STAFF): GHS 38920.00
=====================================================================
```

## Python Version
See `../../../python/oop-exercises/payroll-system/`

## Related
- `payroll-system-polymorphism` — Demonstrates virtual functions and base-class pointers