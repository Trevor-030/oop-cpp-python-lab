from salaried_staff import SalariedStaff
from hourly_staff import HourlyStaff
from commissioned_staff import CommissionedStaff


# Salaried Staff Array
salariedEmployees = [
    SalariedStaff(101, "Kwame Mensah", "Administration", 5000),
    SalariedStaff(102, "Ama Owusu", "Registry", 4500)
]


# Hourly Staff Array
hourlyEmployees = [
    HourlyStaff(201, "John Smith", "Computer Engineering", 40, 50),
    HourlyStaff(202, "Mary Adams", "Electrical Engineering", 30, 60)
]


# Commissioned Staff Array
commissionedEmployees = [
    CommissionedStaff(301, "Kofi Asare", "Admissions", 3000, 10, 200),
    CommissionedStaff(302, "Linda Brown", "Recruitment", 3500, 8, 250)
]


print("\n========== SALARIED STAFF PAYROLL ==========")

for employee in salariedEmployees:
    employee.display()


print("\n========== HOURLY STAFF PAYROLL ==========")

for employee in hourlyEmployees:
    employee.display()


print("\n========== COMMISSIONED STAFF PAYROLL ==========")

for employee in commissionedEmployees:
    employee.display()


print("\n========== COMPLETE PAYROLL REPORT ==========")

print("Salaried Staff Total:")
for employee in salariedEmployees:
    print(employee.employeeNo, employee.employeeName, "£", employee.salary())

print("\nHourly Staff Total:")
for employee in hourlyEmployees:
    print(employee.employeeNo, employee.employeeName, "£", employee.salary())

print("\nCommissioned Staff Total:")
for employee in commissionedEmployees:
    print(employee.employeeNo, employee.employeeName, "£", employee.salary())