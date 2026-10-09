# Payroll System — Alternative Version (Python)

Alternative implementation matching the C++ payroll-system-inheritance exercise data.

## Files
- `employee.py` — Base `Employee` class
- `salaried_staff.py` — `SalariedStaff` derived class
- `hourly_staff.py` — `HourlyStaff` derived class
- `commissioned_staff.py` — `CommissionedStaff` derived class
- `main.py` — Main program with same test data as C++ version

## Differences from Main Version
- **Main version** (`../`): Different test data (Kwame Mensah, John Smith, etc.), £ currency
- **Alt version** (`main.py`): Matches C++ test data exactly (Ama Owusu-Sekyere, Dr. Kojo Boateng, etc.), GHS currency

## Class Hierarchy
Same as main version:
- **Employee** → **SalariedStaff**, **HourlyStaff**, **CommissionedStaff**

## Run
```bash
python main.py
```

## Example Output
Matches C++ `payroll-system-inheritance` output:
```
======================================================================
      UNIVERSITY OF MINES AND TECHNOLOGY - ESSIKADO CAMPUS
                 STAFF PAYROLL REPORT
======================================================================

SALARIED STAFF
----------------------------------------------------------------------
Employee No: 1001
Name: Ama Owusu-Sekyere
Department: Registrar's Office
Salary: GHS 6500.00
----------------------------------------------------------------------
Subtotal - Salaried Staff: GHS 20500.00

HOURLY STAFF
----------------------------------------------------------------------
Employee No: 2001
Name: Dr. Kojo Boateng
Department: Mining Engineering
Hours Worked: 18
Rate Per Hour: GHS 120.00
Salary: GHS 2160.00
----------------------------------------------------------------------
Subtotal - Hourly Staff: GHS 6370.00

COMMISSIONED STAFF
----------------------------------------------------------------------
Employee No: 3001
Name: Abena Nyarko
Department: Admissions & Recruitment
Base Salary: GHS 2500.00
Targets Completed: 9
Bonus Per Target: GHS 150.00
Salary: GHS 3850.00
----------------------------------------------------------------------
Subtotal - Commissioned Staff: GHS 12050.00

======================================================================
TOTAL MONTHLY PAYROLL (ALL STAFF): GHS 38920.00
======================================================================
```

## Related
Main version: `../README.md`
C++ version: `../../../../cpp/oop-exercises/payroll-system-inheritance/`