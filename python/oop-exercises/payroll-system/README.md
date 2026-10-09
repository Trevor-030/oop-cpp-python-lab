# Payroll System (Python)

OOP exercise demonstrating inheritance with an `Employee` base class and three derived classes.

## Files
- `employee.py` — Base `Employee` class
- `salaried_staff.py` — `SalariedStaff` derived class
- `hourly_staff.py` — `HourlyStaff` derived class
- `commissioned_staff.py` — `CommissionedStaff` derived class
- `main.py` — Main program with separate arrays for each type
- `alt-version/` — Alternative implementation

## Class Hierarchy
- **Employee** (base)
  - `employeeNo`, `employeeName`, `department`
  - `display()` — prints basic info
- **SalariedStaff** (Employee)
  - `monthlySalary`
  - `salary()` — returns monthly salary
- **HourlyStaff** (Employee)
  - `hoursWorked`, `ratePerHour`
  - `salary()` — returns `hoursWorked * ratePerHour`
- **CommissionedStaff** (Employee)
  - `baseSalary`, `targetsCompleted`, `bonusPerTarget`
  - `salary()` — returns `baseSalary + targetsCompleted * bonusPerTarget`

## Run
```bash
python main.py
```

## Example Output
```
========== SALARIED STAFF PAYROLL ==========
Employee No: 101
Employee Name: Kwame Mensah
Department: Administration
Salary: £ 5000
------------------------

========== HOURLY STAFF PAYROLL ==========
Employee No: 201
Employee Name: John Smith
Department: Computer Engineering
Hours Worked: 40
Rate Per Hour: £ 50
Salary: £ 2000
------------------------

========== COMMISSIONED STAFF PAYROLL ==========
Employee No: 301
Employee Name: Kofi Asare
Department: Admissions
Base Salary: £ 3000
Targets Completed: 10
Bonus Per Target: £ 200
Salary: £ 5000
------------------------

========== COMPLETE PAYROLL REPORT ==========
Salaried Staff Total:
101 Kwame Mensah £ 5000
102 Ama Owusu £ 4500

Hourly Staff Total:
201 John Smith £ 2000
202 Mary Adams £ 1800

Commissioned Staff Total:
301 Kofi Asare £ 5000
302 Linda Brown £ 5500
```

## C++ Version
See `../../../cpp/oop-exercises/payroll-system-inheritance/`