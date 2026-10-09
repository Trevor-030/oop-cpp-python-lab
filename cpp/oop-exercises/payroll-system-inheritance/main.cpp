#include <iostream>
#include <iomanip>

#include "SalariedStaff.h"
#include "HourlyStaff.h"
#include "CommissionedStaff.h"

using namespace std;

int main()
{
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
