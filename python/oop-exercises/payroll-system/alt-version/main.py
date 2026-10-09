from salaried_staff import SalariedStaff
from hourly_staff import HourlyStaff
from commissioned_staff import CommissionedStaff

# Salaried Staff
salaried_arr = [
    SalariedStaff(1001, "Ama Owusu-Sekyere", "Registrar's Office", 6500.00),
    SalariedStaff(1002, "Kwabena Asante", "Finance Directorate", 7200.00),
    SalariedStaff(1003, "Efua Darkoa Mensah", "Academic Affairs", 6800.00)
]

# Hourly Staff
hourly_arr = [
    HourlyStaff(2001, "Dr. Kojo Boateng", "Mining Engineering", 18, 120.00),
    HourlyStaff(2002, "Ing. Adwoa Frimpong", "Electrical & Electronic Eng.", 22, 110.00),
    HourlyStaff(2003, "Mr. Yaw Antwi", "Geological Engineering", 15, 95.00)
]

# Commissioned Staff
commissioned_arr = [
    CommissionedStaff(3001, "Abena Nyarko", "Admissions & Recruitment", 2500.00, 9, 150.00),
    CommissionedStaff(3002, "Kwesi Appiah", "Admissions & Recruitment", 2500.00, 6, 150.00),
    CommissionedStaff(3003, "Linda Ofosu", "Admissions & Recruitment", 2800.00, 12, 150.00)
]

total_salaried = 0
total_hourly = 0
total_commissioned = 0

print("=" * 70)
print("      UNIVERSITY OF MINES AND TECHNOLOGY - ESSIKADO CAMPUS")
print("                 STAFF PAYROLL REPORT")
print("=" * 70)

print("\nSALARIED STAFF")
print("-" * 70)
for staff in salaried_arr:
    staff.display()
    total_salaried += staff.salary()
    print("-" * 70)

print(f"Subtotal - Salaried Staff: GHS {total_salaried:.2f}\n")

print("HOURLY STAFF")
print("-" * 70)
for staff in hourly_arr:
    staff.display()
    total_hourly += staff.salary()
    print("-" * 70)

print(f"Subtotal - Hourly Staff: GHS {total_hourly:.2f}\n")

print("COMMISSIONED STAFF")
print("-" * 70)
for staff in commissioned_arr:
    staff.display()
    total_commissioned += staff.salary()
    print("-" * 70)

print(f"Subtotal - Commissioned Staff: GHS {total_commissioned:.2f}\n")

grand_total = total_salaried + total_hourly + total_commissioned

print("=" * 70)
print(f"TOTAL MONTHLY PAYROLL (ALL STAFF): GHS {grand_total:.2f}")
print("=" * 70)