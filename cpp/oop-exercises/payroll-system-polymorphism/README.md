# Payroll System — Polymorphism (C++)

OOP exercise demonstrating polymorphism with an abstract `Employee` base class and virtual functions.

## Structure
```
payroll-system-polymorphism/
├── include/
│   ├── Employee.h
│   ├── SalariedEmployee.h
│   ├── HourlyEmployee.h
│   └── CommissionedEmployee.h
├── src/
│   ├── Employee.cpp
│   ├── SalariedEmployee.cpp
│   ├── HourlyEmployee.cpp
│   └── CommissionedEmployee.cpp
├── main.cpp
├── single_file_implementation.cpp (single-file version)
└── Payroll System(Polymorphism).cbp (Code::Blocks project)
```

## Class Hierarchy
- **Employee** (abstract base)
  - Protected: `empNo`, `name`
  - Pure virtual: `salary()`, `display()`
  - Virtual destructor
- **SalariedEmployee** : public Employee
  - Private: `monthlySalary`
  - Overrides `salary()`, `display()`
- **HourlyEmployee** : public Employee
  - Private: `hoursWorked`, `ratePerHour`
  - Overrides `salary()`, `display()`
- **CommissionedEmployee** : public Employee
  - Private: `baseSalary`, `commissionPerItem`, `itemsSold`
  - Overrides `salary()`, `display()`

## Key Concepts
- Abstract base class with pure virtual functions (`= 0`)
- Virtual destructor for proper cleanup
- Polymorphic array: `Employee* staff[SIZE]` holds different derived types
- Dynamic dispatch via `staff[i]->salary()` and `staff[i]->display()`

## Build & Run
```bash
g++ -Iinclude main.cpp src/*.cpp -o payroll_polymorphism
./payroll_polymorphism
```

Or open `Payroll System(Polymorphism).cbp` in Code::Blocks.

## Example Output
```
=======================================================
                 PAYROLL REPORT
=======================================================
EmpNo   Name                 Type            Salary (GHS)
-------------------------------------------------------
101     Ama Boateng          Salaried        3500.00
102     Kojo Mensah          Hourly          1200.00
103     Efua Asante          Commissioned    1600.00
104     Yaw Owusu            Salaried        4200.00
105     Adjoa Sarpong        Hourly          720.00
-------------------------------------------------------
Total number of employees : 5
Total payroll for period   : GHS 11220.00
Average salary             : GHS 2244.00
=======================================================
```

## Related
- `payroll-system-inheritance` — Non-polymorphic version with separate arrays
- `single_file_implementation.cpp` — Same logic in one file