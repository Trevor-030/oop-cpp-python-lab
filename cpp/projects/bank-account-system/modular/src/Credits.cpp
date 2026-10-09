#include "Credits.h"
#include "Console.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void showCredits()
{
    struct Member
    {
        string name;
        string idNumber;
    };

    vector<Member> members = {
        {"Michael Agyenim Boateng Anning", "SRI.41.008.026.25"},
        {"Christian David Takyi", "SRI.41.008.108.25"},
        {"Dawuda Kashafatu", "SRI.41.008.053.25"},
        {"Maame Esi Ohenewaa Andoh", "SRI.41.008.025.25"},
        {"Rita Awuviri", "SRI.41.008.039.25"},
        {"Oduro Appiah Kwaku", "SRI.41.008.089.25"}
    };

    cout << "\n"
         << BOLD << CYAN << "==========================================\n"
         << "            YOU FOUND THE SECRET MENU!    \n"
         << "==========================================\n"
         << RESET;
    cout << YELLOW << "Bank Account Management System - Project Team\n\n" << RESET;

    for (const auto &m : members)
    {
        cout << GREEN << "  * " << RESET << m.name
             << "  " << CYAN << "(" << m.idNumber << ")" << RESET << endl;
    }

    cout << "\n"
         << BOLD << CYAN << "==========================================\n"
         << RESET;
    cout << YELLOW << "Press Enter to return to the menu..." << RESET;
    cin.get();
}
